struct IBuffer 
{
    virtual IBuffer() = 0;
}

struct ViewPort 
{
    int width{10};
    int height{10};
    std::vector<int> horizontalSums;
    std::vector<int> verticalSums;
}

struct TableBuffer : IBuffer
{
    TableBuffer(vector<TableColumnSpec> spec, int
        totalHeight) {  }
    struct TableColumnSpec
    {
        string header;
        int width;
        enum class TableColumnAlignment {
        Left, Center, Right
        }  alignment;
    }
};

struct Console
{
    vector<Viewport*> viewports;
    Size charSize, gridSize;
};

Console::Console(const ConsoleCreationParameters& ccp) 
{
}

struct ConsoleCreationParameters
{
    optional<Size> client_size;
    int character_width{10};
    int character_height{14};
    int width{10};
    int height{10};
    bool fullscreen{false};
    bool create_default_view_and_buffer{true};
};