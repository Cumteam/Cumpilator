const std = @import("std");

pub fn build(b: *std.Build) void {
    const cli = b.addExecutable(.{
        .name = "cum",
        .root_source_file = .{ .path = "src/main.zig" },
    });

    b.installArtifact(cli);
}
