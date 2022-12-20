load("//tools/install:install.bzl", "install", "install_src_files")
load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

filegroup(
    name = "conf",
    srcs = [
        ":example.dag",
        ":example.launch",
    ],
)

install(
    name = "install",
    data = [
        "//example_components/proto:examples_cc_proto",
	":cyberfile.xml"
    ],
    data_dest = "example-components",
    library_dest = "example-components/lib",
    library_strip_prefix = ["src", "proto"],
    targets = [
        "//example_components/src:libcomponent_examples.so",
	    "//example_components/proto:examples_cc_proto"
    ],
    deps = [
        ":pb_headers",
        ":dag",
        ":launch"
    ]
)

install(
    name = "pb_headers",
    data = [
        "//example_components/proto:examples_cc_proto",
    ],
    data_dest = "example-components/include",
)

install(
    name = "dag",
    data = [":example.dag"],
    data_dest = "example-components/dag"
)

install(
    name = "launch",
    data = [":example.launch"],
    data_dest = "example-components/launch"
)

install_src_files(
    name = "headers",
    src_dir = ["src"],
    dest = "example-components/include",
    filter = "*.h",
)

install_src_files(
    name = "install_src",
    src_dir = ["."],
    dest = "example-components/src",
    filter = "*",
    deps = [
        ":headers"
    ]
)
