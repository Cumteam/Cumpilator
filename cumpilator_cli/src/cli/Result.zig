pub const ResultOptionValue = union(enum) {
    string: []u8,
    int: u8,
    bool: bool,
    void: void,
};

pub const ResultOption = struct {
    hasName: bool,
    name: ?[]const u8,
    value: ResultOptionValue,
};

pub const ResultCommand = struct {
    commandName: []const u8,
    options: ?[]ResultOption,
};
