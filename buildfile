./: {*/ -build/ -upstream/ -test_logs/} upstream/doc{README.md LICENSE} doc{README.md LICENSE} manifest

# Don't install tests.
#
tests/: install = false
