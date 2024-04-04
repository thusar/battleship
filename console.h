#include <iostream>
#include <optional>
#include <string>
#include <vector>

struct IBuffer 
{
    
};

struct Viewport 
{
    int width{10};
    int height{10};
    std::vector<int> horizontalSums;
    std::vector<int> verticalSums;
};

struct TableBuffer : IBuffer
{
    struct TableColumnSpec
    {
        std::string header;
        int width;
        enum class TableColumnAlignment {
        Left, Center, Right
        }  alignment;
    };
    TableBuffer(std::vector<TableColumnSpec> spec, int totalHeight) {  }
};

struct ConsoleCreationParameters
{
    std::optional<size_t> client_size;
    int character_width{10};
    int character_height{14};
    int width{10};
    int height{10};
    bool fullscreen{false};
    bool create_default_view_and_buffer{true};
};

struct Console
{
    std::vector<Viewport*> viewports;
    size_t charSize, gridSize;
    Console(const ConsoleCreationParameters& ccp);
};

Console::Console(const ConsoleCreationParameters& ccp) 
{
}

