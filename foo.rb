require 'ffi'

module FOO
  extend FFI::Library
  # ffi_lib './c/libfoo.so'
  ffi_lib './go/libfoo.so'

  attach_function :Hello, [], :void
end

# puts(ENV.inspect)

ENV["FOO"] = "NEW_BAR"
ENV["BAZ"] = "BAR"

print("=========== calling Hello ==================\n")
FOO.Hello()
