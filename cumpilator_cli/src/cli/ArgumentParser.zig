const std = @import("std");

const Command = @import("Command.zig").Command;

pub const ArgumentParser = struct {
    allocator: std.mem.Allocator,
    commands: std.StringHashMap(Command),

    pub fn init(allocator: std.mem.Allocator) ArgumentParser {
        return ArgumentParser{
            .allocator = allocator,
            .commands = std.StringHashMap(Command).init(allocator),
        };
    }

    pub fn deinit(self: *ArgumentParser) void {
        self.commands.deinit();
    }

    pub fn addCommand(self: *ArgumentParser, command: Command) !void {
        // Check if the command name is already in use.
        if (self.commands.contains(command.name))
            return error.InvalidArgument;

        // Check if the command has an anonymous option.
        // If it does, it must be the only option.
        if (command.options) |options| {
            var hasAnonymousOption = false;
            for (options) |option| {
                if (option.hasName == false)
                    hasAnonymousOption = true;
            }

            if (hasAnonymousOption and options.len > 1)
                return error.InvalidArgument;
        }

        try self.commands.put(command.name, command);
    }

    pub fn parse(self: *ArgumentParser, args: *std.process.ArgIterator) !void {
        var arg = args.next();

        // Skip the first argument, which is the program name.
        arg = args.next();

        // Find the command used by the user by its name.
        var command: ?Command = null;
        if (arg) |inputCommandName| {
            command = self.commands.get(inputCommandName);
            if (command == null)
                return error.InvalidCommand;
        } else {
            return error.MissingCommand;
        }
    }
};

test "addCommand with duplicate name" {
    // Allocator initialization
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    const allocator = gpa.allocator();
    defer _ = gpa.deinit();

    // Parser initialization
    var parser = ArgumentParser.init(allocator);
    defer parser.deinit();

    const command: Command = .{
        .description = "test",
        .name = "test",
        .options = null,
    };

    try parser.addCommand(command);
    try std.testing.expectError(error.InvalidArgument, parser.addCommand(command));
}
