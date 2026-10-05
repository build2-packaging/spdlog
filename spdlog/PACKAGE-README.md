# spdlog - C++ logging library

This is a `build2` package for the
[`spdlog`](https://github.com/gabime/spdlog) library. It provides
feature-rich formatting (using the [fmt](https://github.com/fmtlib/fmt)
library), synchronous and asynchronous logging, and a variety of log
sinks (rotating and daily files, console with color support, syslog,
the Windows event log and debugger, and more).

This package builds the compiled (non-header-only) variant of the
library.


## Usage

To start using `spdlog` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as
appropriate:

```
depends: spdlog ^1.17.0
```

Then import the library in your `buildfile`:

```
import libs = spdlog%lib{spdlog}
```


## Importable targets

This package provides the following importable targets:

```
lib{spdlog}
```


## Configuration variables

This package provides no configuration variables.
