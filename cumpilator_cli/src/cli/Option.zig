pub const Option = struct {
    description: []const u8,
    hasName: bool,
    name: ?OptionName,
    required: bool,
    type: OptionType,
};

pub const OptionName = struct {
    long: []const u8,
    short: []const u8,
};

pub const OptionType = enum {
    String,
    Int,
    Bool,
    Void,
};
