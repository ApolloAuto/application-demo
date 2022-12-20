load("//tools:cpplint.bzl", "cpplint")
load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "libcomponent_examples.so",
    linkshared = True,
    linkstatic = True,
    deps = [
        ":timer_common_component_example_lib",
        ":common_component_example_lib"
    ],
)

cc_library(
    name = "timer_common_component_example_lib",
    srcs = ["timer_common_component_example.cc"],
    hdrs = ["timer_common_component_example.h"],
    visibility = ["//visibility:private"],
    alwayslink = True,
    deps = [
        "//cyber",
        "//example_components/proto:examples_cc_proto",
    ],
)

cc_library(
    name = "common_component_example_lib",
    srcs = ["common_component_example.cc"],
    hdrs = ["common_component_example.h"],
    visibility = ["//visibility:private"],
    alwayslink = True,
    deps = [
        "//cyber",
        "//example_components/proto:examples_cc_proto",
    ],
)

cpplint()

