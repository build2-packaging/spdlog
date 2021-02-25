./: {*/ -build/ -upstream/ -test_logs/} doc{README.md} manifest

# Don't install tests.
#
tests/: install = false
