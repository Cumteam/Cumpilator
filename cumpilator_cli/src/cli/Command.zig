const Option = @import("Option.zig").Option;

/// A command that can be run from the command line.
pub const Command = struct {
    name: []const u8,
    description: []const u8,
    options: ?[]const Option,
};
