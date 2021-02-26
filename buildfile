./: {*/ -build/ -upstream/ -test_logs/} doc{README.md LICENSE} manifest

# Don't install tests.
#
tests/: install = false
