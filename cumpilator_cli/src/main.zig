const std = @import("std");

const cli = @import("cli.zig");

const print = std.debug.print;

pub fn main() !void {

    // Allocator initialization
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    const allocator = gpa.allocator();
    defer _ = gpa.deinit();

    // Parser initialization
    var parser = cli.ArgumentParser.init(allocator);
    defer parser.deinit();

    try parser.addCommand(.{
        .name = "help",
        .description = "Prints help information",
        .options = &[_]cli.Option{
            .{
                .description = "Command name",
                .hasName = false,
                .name = null,
                .required = false,
                .type = .String,
            },
        },
    });

    try parser.addCommand(.{
        .name = "version",
        .description = "Prints version information",
        .options = null,
    });

    // Console arguments initialization
    var args = try std.process.ArgIterator.initWithAllocator(allocator);
    defer args.deinit();

    // Parse arguments
    try parser.parse(&args);
}
