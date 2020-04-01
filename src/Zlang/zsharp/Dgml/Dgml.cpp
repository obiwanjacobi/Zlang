#include "Dgml.h"
#include "XmlWriter.h"

namespace dgml
{
    void Graph::Serialize(std::ostream& output)
    {
        // <DirectedGraph xmlns="http://schemas.microsoft.com/vs/2009/dgml">
        XmlWriter::BeginElement(output, "DirectedGraph");
        XmlWriter::Attribute(output, "xmlns", "http://schemas.microsoft.com/vs/2009/dgml");
        XmlWriter::CloseElement(output);

        //  <Nodes />
        XmlWriter::BeginElement(output, "Nodes");
        XmlWriter::CloseElement(output);
        for (const auto node : Nodes)
        {
            node->Serialize(output);
        }
        XmlWriter::EndElement(output, "Nodes");

        //  <Links />
        XmlWriter::BeginElement(output, "Links");
        XmlWriter::CloseElement(output);
        for (const auto link : Links)
        {
            link->Serialize(output);
        }
        XmlWriter::EndElement(output, "Links");

        //  <Categories />
        XmlWriter::BeginElement(output, "Categories");
        XmlWriter::CloseElement(output);
        for (const auto category : Categories)
        {
            category->Serialize(output);
        }
        XmlWriter::EndElement(output, "Categories");

        //  <Styles />

        // </DirectedGraph>
        XmlWriter::EndElement(output, "DirectedGraph");
    }

    void Node::Serialize(std::ostream& output)
    {
        XmlWriter::BeginElement(output, "Node");
        XmlWriter::Attribute(output, "Id", Id);
        if (TypeName.length() > 0)
        {
            XmlWriter::Attribute(output, "Label", "[" + TypeName + "] " + Label);
        }
        else
        {
            XmlWriter::Attribute(output, "Label", Label);
        }
        XmlWriter::Attribute(output, "Category", Category);
        if (Group != Group::NotSet)
        {
            XmlWriter::Attribute(output, "Group", Group == Group::Collapsed ? "Collapsed" : "Expanded");
        }
        XmlWriter::EndCloseElement(output);
    }


    void Link::Serialize(std::ostream& output)
    {
        XmlWriter::BeginElement(output, "Link");
        XmlWriter::Attribute(output, "Source", Source);
        XmlWriter::Attribute(output, "Target", Target);
        XmlWriter::Attribute(output, "Category", Category);
        XmlWriter::EndCloseElement(output);
    }


    void Category::Serialize(std::ostream& output)
    {
        XmlWriter::BeginElement(output, "Category");
        XmlWriter::Attribute(output, "Source", Id);
        XmlWriter::Attribute(output, "Target", Label);
        if (IsContainment)
        {
            XmlWriter::Attribute(output, "IsContainment", "True");
        }
        XmlWriter::EndCloseElement(output);
    }
}