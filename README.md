A simple program to analyze argc/argv/environment variables and shared
library interaction.

Two versions of shared library are there, one in [C](./c/) and another in
[Go](./go/). C one would print argc, argv and env that comes after argv as
well as the explicitly passed envp pointer.

How to run:

1. Build the shared library
```
(cd c/ && make)
```

or

```
(cd go/ && make)
```

2. Run the test program

```
env -i FOO=BAR ruby ./foo.rb
```

Or run it using bundler

```
env -i FOO=BAR bundle exec ruby ./foo.rb
```

Or run it using specific bundler version

```
env -i FOO=BAR ruby ~/.gem/ruby/2.7.0/gems/bundler-2.2.25/exe/bundle exec /usr/bin/ruby ./foo.rb
```

or

```
env -i FOO=BAR ruby ~/.gem/ruby/2.7.0/gems/bundler-2.1.0/exe/bundle exec /usr/bin/ruby ./foo.rb
```
