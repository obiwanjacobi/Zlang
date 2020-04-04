#pragma once

#include <memory>
#include <ostream>
#include <string>
#include <vector>

namespace dgml
{
    enum class Group {
        NotSet,
        Expanded,
        Collapsed,
    };


    class Node;
    class Link;
    class Category;

    class Graph
    {
    public:
        std::string Title;
        std::vector<std::shared_ptr<Node>> Nodes;
        std::vector<std::shared_ptr<Link>> Links;
        std::vector<std::shared_ptr<Category>> Categories;

        void Serialize(std::ostream& output);
    };

    class Node
    {
    public:
        std::string Id;
        std::string Label;
        std::string Category;
        std::string Shape;
        std::string Style;
        Group Group;

        void Serialize(std::ostream& output);

        // extensions
        std::string TypeName;
    };

    class Link
    {
    public:
        std::string Source;
        std::string Target;
        std::string Label;
        std::string Category;

        void Serialize(std::ostream& output);
    };

    class Category
    {
    public:
        std::string Id;
        std::string Label;
        bool IsContainment;

        void Serialize(std::ostream& output);
    };
}