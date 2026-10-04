// Not part of upstream. The test suite initializes spdlog's global async
// thread pool in several test cases but never shuts it down. On MinGW
// shared builds, the registry singleton lives inside the DLL, and its
// destructor runs during DLL_PROCESS_DETACH while the OS holds the loader
// lock, so joining the still-running worker thread there deadlocks the
// process instead of exiting.
//
// A static object's destructor is the wrong place to call spdlog::shutdown():
// destruction order between this translation unit's statics and spdlog's own
// lazily-constructed registry singleton is unspecified, and in practice the
// registry (constructed on first use, during a test) is destroyed before a
// namespace-scope static here (constructed before main()) would be. Calling
// shutdown() from a Catch2 listener's testRunEnded() instead runs it
// synchronously from within main(), strictly before any static destruction
// begins, so there is no ordering hazard on any platform.
#include <catch2/reporters/catch_reporter_event_listener.hpp>
#include <catch2/reporters/catch_reporter_registrars.hpp>
#include <spdlog/spdlog.h>

namespace {

struct spdlog_shutdown_listener : Catch::EventListenerBase {
    using Catch::EventListenerBase::EventListenerBase;

    void testRunEnded(Catch::TestRunStats const &) override { spdlog::shutdown(); }
};

}  // namespace

CATCH_REGISTER_LISTENER(spdlog_shutdown_listener)
