#pragma once

#include <ostream>

static const char* NewLine = "\r\n";

class XmlWriter
{
public:
    static void Xml(std::ostream& output)
    {
        output << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << NewLine;
    }
    static void BeginElement(std::ostream& output, std::string name)
    {
        output << "<" << name;
    }
    static void CloseElement(std::ostream& output)
    {
        output << ">" << NewLine;
    }
    static void EndCloseElement(std::ostream& output)
    {
        output << " />" << NewLine;
    }
    static void EndElement(std::ostream& output, std::string name)
    {
        output << "</" << name << ">" << NewLine;
    }

    static void Attribute(std::ostream& output, std::string name, std::string value)
    {
        if (value.length() == 0) return;
        output << " " << name << "=\"" << value << "\"";
    }
};

