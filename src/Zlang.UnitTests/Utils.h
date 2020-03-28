#pragma once

bool ParserSmokeTest(const char* src);

class DisableDebugAssertScope
{
public:
    DisableDebugAssertScope()
    {
        _hook = _CrtSetReportHook(ReportHook);
        _mode = _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);
        _file = _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
    }
    ~DisableDebugAssertScope()
    {
        _CrtSetReportHook(_hook);
        _CrtSetReportMode(_CRT_ASSERT, _mode);
        _CrtSetReportFile(_CRT_ASSERT, _file);
    }

private:
    _CRT_REPORT_HOOK _hook;
    int _mode;
    void* _file;

    static int ReportHook(int reportType, char* message, int* returnValue)
    {
        if (message != nullptr)
        {
            std::cout << message;
        }
        return true;
    }
};
