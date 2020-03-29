#pragma once

class DirectedGraph;
class DirectedGraphNode;
class DirectedGraphNodeCategory;
class DirectedGraphLink;
class DirectedGraphLinkCategory;
class DirectedGraphCategory;
class DirectedGraphProperty;
class DirectedGraphName;
class DirectedGraphAlias;
class DirectedGraphStyle;
class DirectedGraphStyleCondition;
class DirectedGraphStyleSetter;
class DirectedGraphPath;



enum class HorizontalAlignmentEnum {
    Left,
    Center,
    Right,
};


enum class VerticalAlignmentEnum {
    Top,
    Center,
    Bottom,
};


enum class GroupEnum {
    Expanded,
    Collapsed,
};


enum class ClrBoolean {
    True,
    False,
};


enum class VisibilityEnum {
    Visible,
    Hidden,
    Collapsed,
};


enum class FontStyleEnum {
    Normal,
    Italic,
    Oblique,
};


enum class FontWeightEnum {
    Black,
    Bold,
    DemiBold,
    ExtraBlack,
    ExtraBold,
    ExtraLight,
    Heavy,
    Light,
    Medium,
    Normal,
    Regular,
    Semibold,
    Thin,
    UltraBlack,
    UltraBold,
    UltraLight,
};


enum class FrameKindEnum {
    Conditional,
    Clause,
    Loop,
    Call,
};


enum class PropertyType {
    ArrowHeadSize,
    ArrowHeadWidth,
    Background,
    FontFamily,
    FontSize,
    FontStyle,
    FontWeight,
    Foreground,
    HorizontalAlignment,
    Icon,
    Image,
    MinWidth,
    MaxWidth,
    NodeRadius,
    SelectedStroke,
    ShadowDepth,
    Shape,
    Stroke,
    StrokeDashArray,
    StrokeThickness,
    Style,
};

enum class TargetTypeEnum {
    Node,
    Link,
};

enum class GraphDirectionEnum {
    TopToBottom,
    BottomToTop,
    LeftToRight,
    RightToLeft,
};

enum class LayoutEnum {
    None,
    Sugiyama,
    ForceDirected,
    DependencyMatrix,
};


class DirectedGraph {

private: cli::array< DirectedGraphNode^  >^ nodesField;

private: cli::array< DirectedGraphLink^  >^ linksField;

private: cli::array< DirectedGraphCategory^  >^ categoriesField;

private: cli::array< DirectedGraphProperty^  >^ propertiesField;

private: cli::array< DirectedGraphName^  >^ qualifiedNamesField;

private: cli::array< DirectedGraphAlias^  >^ identifierAliasesField;

private: cli::array< DirectedGraphStyle^  >^ stylesField;

private: cli::array< DirectedGraphPath^  >^ pathsField;

private: System::String^ titleField;

private: System::String^ backgroundField;

private: System::String^ backgroundImageField;

private: GraphDirectionEnum graphDirectionField;

private: System::Boolean graphDirectionFieldSpecified;

private: LayoutEnum layoutField;

private: System::Boolean layoutFieldSpecified;

private: ClrBoolean butterflyModeField;

private: System::Boolean butterflyModeFieldSpecified;

private: System::String^ neighborhoodDistanceField;

private: System::String^ zoomLevelField;


public: [System::Xml::Serialization::XmlArrayItemAttribute(L"Node", IsNullable = false)]
    property cli::array< DirectedGraphNode^  >^ Nodes {
    cli::array< DirectedGraphNode^  >^ get();
    System::Void set(cli::array< DirectedGraphNode^  >^ value);
}


public: [System::Xml::Serialization::XmlArrayItemAttribute(L"Link", IsNullable = false)]
    property cli::array< DirectedGraphLink^  >^ Links {
    cli::array< DirectedGraphLink^  >^ get();
    System::Void set(cli::array< DirectedGraphLink^  >^ value);
}


public: [System::Xml::Serialization::XmlArrayItemAttribute(L"Category", IsNullable = false)]
    property cli::array< DirectedGraphCategory^  >^ Categories {
    cli::array< DirectedGraphCategory^  >^ get();
    System::Void set(cli::array< DirectedGraphCategory^  >^ value);
}


public: [System::Xml::Serialization::XmlArrayItemAttribute(L"Property", IsNullable = false)]
    property cli::array< DirectedGraphProperty^  >^ Properties {
    cli::array< DirectedGraphProperty^  >^ get();
    System::Void set(cli::array< DirectedGraphProperty^  >^ value);
}


public: [System::Xml::Serialization::XmlArrayItemAttribute(L"Name", IsNullable = false)]
    property cli::array< DirectedGraphName^  >^ QualifiedNames {
    cli::array< DirectedGraphName^  >^ get();
    System::Void set(cli::array< DirectedGraphName^  >^ value);
}


public: [System::Xml::Serialization::XmlArrayItemAttribute(L"Alias", IsNullable = false)]
    property cli::array< DirectedGraphAlias^  >^ IdentifierAliases {
    cli::array< DirectedGraphAlias^  >^ get();
    System::Void set(cli::array< DirectedGraphAlias^  >^ value);
}


public: [System::Xml::Serialization::XmlArrayItemAttribute(L"Style", IsNullable = false)]
    property cli::array< DirectedGraphStyle^  >^ Styles {
    cli::array< DirectedGraphStyle^  >^ get();
    System::Void set(cli::array< DirectedGraphStyle^  >^ value);
}


public: [System::Xml::Serialization::XmlArrayItemAttribute(L"Path", IsNullable = false)]
    property cli::array< DirectedGraphPath^  >^ Paths {
    cli::array< DirectedGraphPath^  >^ get();
    System::Void set(cli::array< DirectedGraphPath^  >^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Title {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Background {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ BackgroundImage {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property GraphDirectionEnum GraphDirection {
    GraphDirectionEnum get();
    System::Void set(GraphDirectionEnum value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean GraphDirectionSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property LayoutEnum Layout {
    LayoutEnum get();
    System::Void set(LayoutEnum value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean LayoutSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean ButterflyMode {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean ButterflyModeSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute(DataType = L"integer")]
    property System::String^ NeighborhoodDistance {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ ZoomLevel {
    System::String^ get();
    System::Void set(System::String^ value);
}
};







class DirectedGraphNode {

private: cli::array< DirectedGraphNodeCategory^  >^ categoryField;

private: System::String^ idField;

private: System::String^ category1Field;

private: System::String^ iconField;

private: System::String^ shapeField;

private: System::String^ styleField;

private: HorizontalAlignmentEnum horizontalAlignmentField;

private: System::Boolean horizontalAlignmentFieldSpecified;

private: VerticalAlignmentEnum verticalAlignmentField;

private: System::Boolean verticalAlignmentFieldSpecified;

private: System::Double minWidthField;

private: System::Boolean minWidthFieldSpecified;

private: System::Double maxWidthField;

private: System::Boolean maxWidthFieldSpecified;

private: System::Double nodeRadiusField;

private: System::Boolean nodeRadiusFieldSpecified;

private: System::String^ descriptionField;

private: GroupEnum groupField;

private: System::Boolean groupFieldSpecified;

private: ClrBoolean isVerticalField;

private: System::Boolean isVerticalFieldSpecified;

private: System::String^ referenceField;

private: System::String^ labelField;

private: VisibilityEnum visibilityField;

private: System::Boolean visibilityFieldSpecified;

private: System::String^ backgroundField;

private: System::Double fontSizeField;

private: System::Boolean fontSizeFieldSpecified;

private: System::String^ fontFamilyField;

private: FontStyleEnum fontStyleField;

private: System::Boolean fontStyleFieldSpecified;

private: FontWeightEnum fontWeightField;

private: System::Boolean fontWeightFieldSpecified;

private: System::String^ strokeField;

private: System::String^ strokeThicknessField;

private: System::String^ strokeDashArrayField;

private: System::String^ accessField;

private: System::String^ assemblyField;

private: System::String^ filePathField;

private: System::String^ functionTypeFlagsField;

private: ClrBoolean isAbstractField;

private: System::Boolean isAbstractFieldSpecified;

private: ClrBoolean isCodeTypeField;

private: System::Boolean isCodeTypeFieldSpecified;

private: ClrBoolean isHubField;

private: System::Boolean isHubFieldSpecified;

private: ClrBoolean isOverloadedField;

private: System::Boolean isOverloadedFieldSpecified;

private: ClrBoolean isOverridableField;

private: System::Boolean isOverridableFieldSpecified;

private: System::String^ languageField;

private: System::String^ locationField;

private: System::Int32 linesOfCodeField;

private: System::Boolean linesOfCodeFieldSpecified;

private: System::String^ namespaceField;

private: System::String^ mustImplementField;

private: System::String^ typeNameField;

private: ClrBoolean isDocumentationField;

private: System::Boolean isDocumentationFieldSpecified;

private: System::String^ codeGenSourceNameField;

private: System::String^ codeGenTargetNameField;

private: ClrBoolean codeGenIncomingField;

private: System::Boolean codeGenIncomingFieldSpecified;

private: System::Int32 codeSchemaProperty_CallSequenceNumberField;

private: System::Boolean codeSchemaProperty_CallSequenceNumberFieldSpecified;

private: ClrBoolean codeSchemaProperty_DisableEnabledErrorHandlerField;

private: System::Boolean codeSchemaProperty_DisableEnabledErrorHandlerFieldSpecified;

private: ClrBoolean codeSchemaProperty_DisableEnabledExceptionField;

private: System::Boolean codeSchemaProperty_DisableEnabledExceptionFieldSpecified;

private: System::Int32 codeSchemaProperty_EndColumnField;

private: System::Boolean codeSchemaProperty_EndColumnFieldSpecified;

private: System::Int32 codeSchemaProperty_EndLineField;

private: System::Boolean codeSchemaProperty_EndLineFieldSpecified;

private: System::Int32 codeSchemaProperty_FrameDepthField;

private: System::Boolean codeSchemaProperty_FrameDepthFieldSpecified;

private: FrameKindEnum codeSchemaProperty_FrameKindField;

private: System::Boolean codeSchemaProperty_FrameKindFieldSpecified;

private: System::String^ codeSchemaProperty_IconField;

private: System::String^ codeSchemaProperty_InstanceTrackingInformationField;

private: ClrBoolean codeSchemaProperty_IsAbstractField;

private: System::Boolean codeSchemaProperty_IsAbstractFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsAnonymousField;

private: System::Boolean codeSchemaProperty_IsAnonymousFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsArrayField;

private: System::Boolean codeSchemaProperty_IsArrayFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsByReferenceField;

private: System::Boolean codeSchemaProperty_IsByReferenceFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsCallToThisField;

private: System::Boolean codeSchemaProperty_IsCallToThisFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsConstructorField;

private: System::Boolean codeSchemaProperty_IsConstructorFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsDoField;

private: System::Boolean codeSchemaProperty_IsDoFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsFinalField;

private: System::Boolean codeSchemaProperty_IsFinalFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsForField;

private: System::Boolean codeSchemaProperty_IsForFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsForEachField;

private: System::Boolean codeSchemaProperty_IsForEachFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsGenericField;

private: System::Boolean codeSchemaProperty_IsGenericFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsGenericInstanceField;

private: System::Boolean codeSchemaProperty_IsGenericInstanceFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsInternalField;

private: System::Boolean codeSchemaProperty_IsInternalFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsHideBySignatureField;

private: System::Boolean codeSchemaProperty_IsHideBySignatureFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsOperatorField;

private: System::Boolean codeSchemaProperty_IsOperatorFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsOutField;

private: System::Boolean codeSchemaProperty_IsOutFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsParameterArrayField;

private: System::Boolean codeSchemaProperty_IsParameterArrayFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsPrivateField;

private: System::Boolean codeSchemaProperty_IsPrivateFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsProtectedField;

private: System::Boolean codeSchemaProperty_IsProtectedFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsProtectedOrInternalField;

private: System::Boolean codeSchemaProperty_IsProtectedOrInternalFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsPropertyGetField;

private: System::Boolean codeSchemaProperty_IsPropertyGetFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsPropertySetField;

private: System::Boolean codeSchemaProperty_IsPropertySetFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsPrototypeField;

private: System::Boolean codeSchemaProperty_IsPrototypeFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsPublicField;

private: System::Boolean codeSchemaProperty_IsPublicFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsSpecialNameField;

private: System::Boolean codeSchemaProperty_IsSpecialNameFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsStaticField;

private: System::Boolean codeSchemaProperty_IsStaticFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsUntilLoopField;

private: System::Boolean codeSchemaProperty_IsUntilLoopFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsVirtualField;

private: System::Boolean codeSchemaProperty_IsVirtualFieldSpecified;

private: ClrBoolean codeSchemaProperty_IsWhileField;

private: System::Boolean codeSchemaProperty_IsWhileFieldSpecified;

private: ClrBoolean codeSchemaProperty_PreserveDataField;

private: System::Boolean codeSchemaProperty_PreserveDataFieldSpecified;

private: ClrBoolean codeSchemaProperty_SingleInstanceSourceLinkField;

private: System::Boolean codeSchemaProperty_SingleInstanceSourceLinkFieldSpecified;

private: ClrBoolean codeSchemaProperty_SingleInstanceTargetLinkField;

private: System::Boolean codeSchemaProperty_SingleInstanceTargetLinkFieldSpecified;

private: System::String^ codeSchemaProperty_SourceTextField;

private: System::Int32 codeSchemaProperty_StartColumnField;

private: System::Boolean codeSchemaProperty_StartColumnFieldSpecified;

private: System::Int32 codeSchemaProperty_StartLineField;

private: System::Boolean codeSchemaProperty_StartLineFieldSpecified;

private: System::String^ codeSchemaProperty_StatementKindField;

private: System::Int32 codeSchemaProperty_StatementNumberField;

private: System::Boolean codeSchemaProperty_StatementNumberFieldSpecified;

private: System::String^ codeSchemaProperty_StatementTypeField;


public: [System::Xml::Serialization::XmlElementAttribute(L"Category")]
    property cli::array< DirectedGraphNodeCategory^  >^ Category {
    cli::array< DirectedGraphNodeCategory^  >^ get();
    System::Void set(cli::array< DirectedGraphNodeCategory^  >^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Id {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute(L"Category")]
    property System::String^ Category1 {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Icon {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Shape {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Style {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property HorizontalAlignmentEnum HorizontalAlignment {
    HorizontalAlignmentEnum get();
    System::Void set(HorizontalAlignmentEnum value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean HorizontalAlignmentSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property VerticalAlignmentEnum VerticalAlignment {
    VerticalAlignmentEnum get();
    System::Void set(VerticalAlignmentEnum value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean VerticalAlignmentSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::Double MinWidth {
    System::Double get();
    System::Void set(System::Double value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean MinWidthSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::Double MaxWidth {
    System::Double get();
    System::Void set(System::Double value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean MaxWidthSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::Double NodeRadius {
    System::Double get();
    System::Void set(System::Double value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean NodeRadiusSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Description {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property GroupEnum Group {
    GroupEnum get();
    System::Void set(GroupEnum value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean GroupSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean IsVertical {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean IsVerticalSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Reference {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Label {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property VisibilityEnum Visibility {
    VisibilityEnum get();
    System::Void set(VisibilityEnum value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean VisibilitySpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Background {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::Double FontSize {
    System::Double get();
    System::Void set(System::Double value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean FontSizeSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ FontFamily {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property FontStyleEnum FontStyle {
    FontStyleEnum get();
    System::Void set(FontStyleEnum value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean FontStyleSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property FontWeightEnum FontWeight {
    FontWeightEnum get();
    System::Void set(FontWeightEnum value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean FontWeightSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Stroke {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ StrokeThickness {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ StrokeDashArray {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Access {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Assembly {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ FilePath {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ FunctionTypeFlags {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean IsAbstract {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean IsAbstractSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean IsCodeType {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean IsCodeTypeSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean IsHub {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean IsHubSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean IsOverloaded {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean IsOverloadedSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean IsOverridable {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean IsOverridableSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Language {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Location {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::Int32 LinesOfCode {
    System::Int32 get();
    System::Void set(System::Int32 value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean LinesOfCodeSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Namespace {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ MustImplement {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ TypeName {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean IsDocumentation {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean IsDocumentationSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ CodeGenSourceName {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ CodeGenTargetName {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeGenIncoming {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeGenIncomingSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::Int32 CodeSchemaProperty_CallSequenceNumber {
    System::Int32 get();
    System::Void set(System::Int32 value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_CallSequenceNumberSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_DisableEnabledErrorHandler {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_DisableEnabledErrorHandlerSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_DisableEnabledException {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_DisableEnabledExceptionSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::Int32 CodeSchemaProperty_EndColumn {
    System::Int32 get();
    System::Void set(System::Int32 value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_EndColumnSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::Int32 CodeSchemaProperty_EndLine {
    System::Int32 get();
    System::Void set(System::Int32 value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_EndLineSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::Int32 CodeSchemaProperty_FrameDepth {
    System::Int32 get();
    System::Void set(System::Int32 value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_FrameDepthSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property FrameKindEnum CodeSchemaProperty_FrameKind {
    FrameKindEnum get();
    System::Void set(FrameKindEnum value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_FrameKindSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ CodeSchemaProperty_Icon {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ CodeSchemaProperty_InstanceTrackingInformation {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsAbstract {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsAbstractSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsAnonymous {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsAnonymousSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsArray {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsArraySpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsByReference {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsByReferenceSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsCallToThis {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsCallToThisSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsConstructor {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsConstructorSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsDo {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsDoSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsFinal {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsFinalSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsFor {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsForSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsForEach {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsForEachSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsGeneric {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsGenericSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsGenericInstance {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsGenericInstanceSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsInternal {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsInternalSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsHideBySignature {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsHideBySignatureSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsOperator {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsOperatorSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsOut {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsOutSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsParameterArray {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsParameterArraySpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsPrivate {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsPrivateSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsProtected {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsProtectedSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsProtectedOrInternal {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsProtectedOrInternalSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsPropertyGet {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsPropertyGetSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsPropertySet {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsPropertySetSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsPrototype {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsPrototypeSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsPublic {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsPublicSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsSpecialName {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsSpecialNameSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsStatic {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsStaticSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsUntilLoop {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsUntilLoopSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsVirtual {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsVirtualSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_IsWhile {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_IsWhileSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_PreserveData {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_PreserveDataSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_SingleInstanceSourceLink {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_SingleInstanceSourceLinkSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean CodeSchemaProperty_SingleInstanceTargetLink {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_SingleInstanceTargetLinkSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ CodeSchemaProperty_SourceText {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::Int32 CodeSchemaProperty_StartColumn {
    System::Int32 get();
    System::Void set(System::Int32 value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_StartColumnSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::Int32 CodeSchemaProperty_StartLine {
    System::Int32 get();
    System::Void set(System::Int32 value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_StartLineSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ CodeSchemaProperty_StatementKind {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::Int32 CodeSchemaProperty_StatementNumber {
    System::Int32 get();
    System::Void set(System::Int32 value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean CodeSchemaProperty_StatementNumberSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ CodeSchemaProperty_StatementType {
    System::String^ get();
    System::Void set(System::String^ value);
}
};







class DirectedGraphNodeCategory {

private: System::String^ refField;


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Ref {
    System::String^ get();
    System::Void set(System::String^ value);
}
};







class DirectedGraphLink {

private: cli::array< DirectedGraphLinkCategory^  >^ categoryField;

private: System::String^ labelField;

private: VisibilityEnum visibilityField;

private: System::Boolean visibilityFieldSpecified;

private: System::String^ backgroundField;

private: System::Double fontSizeField;

private: System::Boolean fontSizeFieldSpecified;

private: System::String^ fontFamilyField;

private: FontStyleEnum fontStyleField;

private: System::Boolean fontStyleFieldSpecified;

private: FontWeightEnum fontWeightField;

private: System::Boolean fontWeightFieldSpecified;

private: System::String^ strokeField;

private: System::String^ strokeThicknessField;

private: System::String^ strokeDashArrayField;

private: System::String^ sourceField;

private: System::String^ targetField;

private: System::String^ category1Field;

private: ClrBoolean seederField;

private: System::Boolean seederFieldSpecified;

private: ClrBoolean attractConsumersField;

private: System::Boolean attractConsumersFieldSpecified;


public: [System::Xml::Serialization::XmlElementAttribute(L"Category")]
    property cli::array< DirectedGraphLinkCategory^  >^ Category {
    cli::array< DirectedGraphLinkCategory^  >^ get();
    System::Void set(cli::array< DirectedGraphLinkCategory^  >^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Label {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property VisibilityEnum Visibility {
    VisibilityEnum get();
    System::Void set(VisibilityEnum value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean VisibilitySpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Background {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::Double FontSize {
    System::Double get();
    System::Void set(System::Double value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean FontSizeSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ FontFamily {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property FontStyleEnum FontStyle {
    FontStyleEnum get();
    System::Void set(FontStyleEnum value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean FontStyleSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property FontWeightEnum FontWeight {
    FontWeightEnum get();
    System::Void set(FontWeightEnum value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean FontWeightSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Stroke {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ StrokeThickness {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ StrokeDashArray {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Source {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Target {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute(L"Category")]
    property System::String^ Category1 {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean Seeder {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean SeederSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean AttractConsumers {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean AttractConsumersSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}
};







class DirectedGraphLinkCategory {

private: System::String^ refField;


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Ref {
    System::String^ get();
    System::Void set(System::String^ value);
}
};







class DirectedGraphCategory {

private: System::String^ idField;

private: System::String^ basedOnField;

private: System::String^ labelField;

private: VisibilityEnum visibilityField;

private: System::Boolean visibilityFieldSpecified;

private: System::String^ backgroundField;

private: System::Double fontSizeField;

private: System::Boolean fontSizeFieldSpecified;

private: System::String^ fontFamilyField;

private: FontStyleEnum fontStyleField;

private: System::Boolean fontStyleFieldSpecified;

private: FontWeightEnum fontWeightField;

private: System::Boolean fontWeightFieldSpecified;

private: System::String^ strokeField;

private: System::String^ strokeThicknessField;

private: System::String^ strokeDashArrayField;

private: System::String^ iconField;

private: System::String^ shapeField;

private: System::String^ styleField;

private: HorizontalAlignmentEnum horizontalAlignmentField;

private: System::Boolean horizontalAlignmentFieldSpecified;

private: VerticalAlignmentEnum verticalAlignmentField;

private: System::Boolean verticalAlignmentFieldSpecified;

private: System::Double minWidthField;

private: System::Boolean minWidthFieldSpecified;

private: System::Double maxWidthField;

private: System::Boolean maxWidthFieldSpecified;

private: System::Double nodeRadiusField;

private: System::Boolean nodeRadiusFieldSpecified;

private: System::String^ canLinkedNodesBeDataDrivenField;

private: System::String^ canBeDataDrivenField;

private: System::String^ defaultActionField;

private: System::String^ incomingActionLabelField;

private: ClrBoolean isProviderRootField;

private: System::Boolean isProviderRootFieldSpecified;

private: ClrBoolean isContainmentField;

private: System::Boolean isContainmentFieldSpecified;

private: ClrBoolean isTagField;

private: System::Boolean isTagFieldSpecified;

private: System::String^ navigationActionLabelField;

private: System::String^ outgoingActionLabelField;

private: System::String^ sourceCategoryField;

private: System::String^ targetCategoryField;

private: System::String^ detailsField;

private: System::String^ inboundNameField;

private: System::String^ outboundNameField;


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Id {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ BasedOn {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Label {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property VisibilityEnum Visibility {
    VisibilityEnum get();
    System::Void set(VisibilityEnum value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean VisibilitySpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Background {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::Double FontSize {
    System::Double get();
    System::Void set(System::Double value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean FontSizeSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ FontFamily {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property FontStyleEnum FontStyle {
    FontStyleEnum get();
    System::Void set(FontStyleEnum value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean FontStyleSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property FontWeightEnum FontWeight {
    FontWeightEnum get();
    System::Void set(FontWeightEnum value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean FontWeightSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Stroke {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ StrokeThickness {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ StrokeDashArray {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Icon {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Shape {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Style {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property HorizontalAlignmentEnum HorizontalAlignment {
    HorizontalAlignmentEnum get();
    System::Void set(HorizontalAlignmentEnum value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean HorizontalAlignmentSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property VerticalAlignmentEnum VerticalAlignment {
    VerticalAlignmentEnum get();
    System::Void set(VerticalAlignmentEnum value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean VerticalAlignmentSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::Double MinWidth {
    System::Double get();
    System::Void set(System::Double value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean MinWidthSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::Double MaxWidth {
    System::Double get();
    System::Void set(System::Double value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean MaxWidthSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::Double NodeRadius {
    System::Double get();
    System::Void set(System::Double value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean NodeRadiusSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ CanLinkedNodesBeDataDriven {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ CanBeDataDriven {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ DefaultAction {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ IncomingActionLabel {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean IsProviderRoot {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean IsProviderRootSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean IsContainment {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean IsContainmentSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean IsTag {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean IsTagSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ NavigationActionLabel {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ OutgoingActionLabel {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ SourceCategory {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ TargetCategory {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Details {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ InboundName {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ OutboundName {
    System::String^ get();
    System::Void set(System::String^ value);
}
};







class DirectedGraphProperty {

private: System::String^ idField;

private: ClrBoolean isReferenceField;

private: System::Boolean isReferenceFieldSpecified;

private: System::String^ labelField;

private: System::String^ dataTypeField;

private: System::String^ descriptionField;

private: System::String^ groupField;

private: System::String^ referenceTemplateField;


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Id {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean IsReference {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean IsReferenceSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Label {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ DataType {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Description {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Group {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ ReferenceTemplate {
    System::String^ get();
    System::Void set(System::String^ value);
}
};







class DirectedGraphName {

private: System::String^ idField;

private: System::String^ labelField;

private: System::String^ valueTypeField;

private: System::String^ formatterField;


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Id {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Label {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ ValueType {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Formatter {
    System::String^ get();
    System::Void set(System::String^ value);
}
};







class DirectedGraphAlias {

private: System::Byte nField;

private: System::String^ uriField;

private: System::String^ idField;


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::Byte n {
    System::Byte get();
    System::Void set(System::Byte value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Uri {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Id {
    System::String^ get();
    System::Void set(System::String^ value);
}
};







class DirectedGraphStyle {

private: DirectedGraphStyleCondition^ conditionField;

private: cli::array< DirectedGraphStyleSetter^  >^ setterField;

private: TargetTypeEnum targetTypeField;

private: ClrBoolean isEnabledField;

private: System::Boolean isEnabledFieldSpecified;

private: System::String^ groupLabelField;

private: System::String^ valueLabelField;

private: System::String^ toolTipField;


public: property DirectedGraphStyleCondition^ Condition {
    DirectedGraphStyleCondition^ get();
    System::Void set(DirectedGraphStyleCondition^ value);
}


public: [System::Xml::Serialization::XmlElementAttribute(L"Setter")]
    property cli::array< DirectedGraphStyleSetter^  >^ Setter {
    cli::array< DirectedGraphStyleSetter^  >^ get();
    System::Void set(cli::array< DirectedGraphStyleSetter^  >^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property TargetTypeEnum TargetType {
    TargetTypeEnum get();
    System::Void set(TargetTypeEnum value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property ClrBoolean IsEnabled {
    ClrBoolean get();
    System::Void set(ClrBoolean value);
}


public: [System::Xml::Serialization::XmlIgnoreAttribute]
    property System::Boolean IsEnabledSpecified {
    System::Boolean get();
    System::Void set(System::Boolean value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ GroupLabel {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ ValueLabel {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ ToolTip {
    System::String^ get();
    System::Void set(System::String^ value);
}
};







class DirectedGraphStyleCondition {

private: System::String^ expressionField;


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Expression {
    System::String^ get();
    System::Void set(System::String^ value);
}
};







class DirectedGraphStyleSetter {

private: PropertyType propertyField;

private: System::String^ valueField;

private: System::String^ expressionField;


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property PropertyType Property {
    PropertyType get();
    System::Void set(PropertyType value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Value {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Expression {
    System::String^ get();
    System::Void set(System::String^ value);
}
};







class DirectedGraphPath {

private: System::String^ idField;

private: System::String^ valueField;


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Id {
    System::String^ get();
    System::Void set(System::String^ value);
}


public: [System::Xml::Serialization::XmlAttributeAttribute]
    property System::String^ Value {
    System::String^ get();
    System::Void set(System::String^ value);
}
};














inline cli::array< DirectedGraphNode^  >^ DirectedGraph::Nodes::get() {
    return this->nodesField;
}
inline System::Void DirectedGraph::Nodes::set(cli::array< DirectedGraphNode^  >^ value) {
    this->nodesField = value;
}

inline cli::array< DirectedGraphLink^  >^ DirectedGraph::Links::get() {
    return this->linksField;
}
inline System::Void DirectedGraph::Links::set(cli::array< DirectedGraphLink^  >^ value) {
    this->linksField = value;
}

inline cli::array< DirectedGraphCategory^  >^ DirectedGraph::Categories::get() {
    return this->categoriesField;
}
inline System::Void DirectedGraph::Categories::set(cli::array< DirectedGraphCategory^  >^ value) {
    this->categoriesField = value;
}

inline cli::array< DirectedGraphProperty^  >^ DirectedGraph::Properties::get() {
    return this->propertiesField;
}
inline System::Void DirectedGraph::Properties::set(cli::array< DirectedGraphProperty^  >^ value) {
    this->propertiesField = value;
}

inline cli::array< DirectedGraphName^  >^ DirectedGraph::QualifiedNames::get() {
    return this->qualifiedNamesField;
}
inline System::Void DirectedGraph::QualifiedNames::set(cli::array< DirectedGraphName^  >^ value) {
    this->qualifiedNamesField = value;
}

inline cli::array< DirectedGraphAlias^  >^ DirectedGraph::IdentifierAliases::get() {
    return this->identifierAliasesField;
}
inline System::Void DirectedGraph::IdentifierAliases::set(cli::array< DirectedGraphAlias^  >^ value) {
    this->identifierAliasesField = value;
}

inline cli::array< DirectedGraphStyle^  >^ DirectedGraph::Styles::get() {
    return this->stylesField;
}
inline System::Void DirectedGraph::Styles::set(cli::array< DirectedGraphStyle^  >^ value) {
    this->stylesField = value;
}

inline cli::array< DirectedGraphPath^  >^ DirectedGraph::Paths::get() {
    return this->pathsField;
}
inline System::Void DirectedGraph::Paths::set(cli::array< DirectedGraphPath^  >^ value) {
    this->pathsField = value;
}

inline System::String^ DirectedGraph::Title::get() {
    return this->titleField;
}
inline System::Void DirectedGraph::Title::set(System::String^ value) {
    this->titleField = value;
}

inline System::String^ DirectedGraph::Background::get() {
    return this->backgroundField;
}
inline System::Void DirectedGraph::Background::set(System::String^ value) {
    this->backgroundField = value;
}

inline System::String^ DirectedGraph::BackgroundImage::get() {
    return this->backgroundImageField;
}
inline System::Void DirectedGraph::BackgroundImage::set(System::String^ value) {
    this->backgroundImageField = value;
}

inline GraphDirectionEnum DirectedGraph::GraphDirection::get() {
    return this->graphDirectionField;
}
inline System::Void DirectedGraph::GraphDirection::set(GraphDirectionEnum value) {
    this->graphDirectionField = value;
}

inline System::Boolean DirectedGraph::GraphDirectionSpecified::get() {
    return this->graphDirectionFieldSpecified;
}
inline System::Void DirectedGraph::GraphDirectionSpecified::set(System::Boolean value) {
    this->graphDirectionFieldSpecified = value;
}

inline LayoutEnum DirectedGraph::Layout::get() {
    return this->layoutField;
}
inline System::Void DirectedGraph::Layout::set(LayoutEnum value) {
    this->layoutField = value;
}

inline System::Boolean DirectedGraph::LayoutSpecified::get() {
    return this->layoutFieldSpecified;
}
inline System::Void DirectedGraph::LayoutSpecified::set(System::Boolean value) {
    this->layoutFieldSpecified = value;
}

inline ClrBoolean DirectedGraph::ButterflyMode::get() {
    return this->butterflyModeField;
}
inline System::Void DirectedGraph::ButterflyMode::set(ClrBoolean value) {
    this->butterflyModeField = value;
}

inline System::Boolean DirectedGraph::ButterflyModeSpecified::get() {
    return this->butterflyModeFieldSpecified;
}
inline System::Void DirectedGraph::ButterflyModeSpecified::set(System::Boolean value) {
    this->butterflyModeFieldSpecified = value;
}

inline System::String^ DirectedGraph::NeighborhoodDistance::get() {
    return this->neighborhoodDistanceField;
}
inline System::Void DirectedGraph::NeighborhoodDistance::set(System::String^ value) {
    this->neighborhoodDistanceField = value;
}

inline System::String^ DirectedGraph::ZoomLevel::get() {
    return this->zoomLevelField;
}
inline System::Void DirectedGraph::ZoomLevel::set(System::String^ value) {
    this->zoomLevelField = value;
}


inline cli::array< DirectedGraphNodeCategory^  >^ DirectedGraphNode::Category::get() {
    return this->categoryField;
}
inline System::Void DirectedGraphNode::Category::set(cli::array< DirectedGraphNodeCategory^  >^ value) {
    this->categoryField = value;
}

inline System::String^ DirectedGraphNode::Id::get() {
    return this->idField;
}
inline System::Void DirectedGraphNode::Id::set(System::String^ value) {
    this->idField = value;
}

inline System::String^ DirectedGraphNode::Category1::get() {
    return this->category1Field;
}
inline System::Void DirectedGraphNode::Category1::set(System::String^ value) {
    this->category1Field = value;
}

inline System::String^ DirectedGraphNode::Icon::get() {
    return this->iconField;
}
inline System::Void DirectedGraphNode::Icon::set(System::String^ value) {
    this->iconField = value;
}

inline System::String^ DirectedGraphNode::Shape::get() {
    return this->shapeField;
}
inline System::Void DirectedGraphNode::Shape::set(System::String^ value) {
    this->shapeField = value;
}

inline System::String^ DirectedGraphNode::Style::get() {
    return this->styleField;
}
inline System::Void DirectedGraphNode::Style::set(System::String^ value) {
    this->styleField = value;
}

inline HorizontalAlignmentEnum DirectedGraphNode::HorizontalAlignment::get() {
    return this->horizontalAlignmentField;
}
inline System::Void DirectedGraphNode::HorizontalAlignment::set(HorizontalAlignmentEnum value) {
    this->horizontalAlignmentField = value;
}

inline System::Boolean DirectedGraphNode::HorizontalAlignmentSpecified::get() {
    return this->horizontalAlignmentFieldSpecified;
}
inline System::Void DirectedGraphNode::HorizontalAlignmentSpecified::set(System::Boolean value) {
    this->horizontalAlignmentFieldSpecified = value;
}

inline VerticalAlignmentEnum DirectedGraphNode::VerticalAlignment::get() {
    return this->verticalAlignmentField;
}
inline System::Void DirectedGraphNode::VerticalAlignment::set(VerticalAlignmentEnum value) {
    this->verticalAlignmentField = value;
}

inline System::Boolean DirectedGraphNode::VerticalAlignmentSpecified::get() {
    return this->verticalAlignmentFieldSpecified;
}
inline System::Void DirectedGraphNode::VerticalAlignmentSpecified::set(System::Boolean value) {
    this->verticalAlignmentFieldSpecified = value;
}

inline System::Double DirectedGraphNode::MinWidth::get() {
    return this->minWidthField;
}
inline System::Void DirectedGraphNode::MinWidth::set(System::Double value) {
    this->minWidthField = value;
}

inline System::Boolean DirectedGraphNode::MinWidthSpecified::get() {
    return this->minWidthFieldSpecified;
}
inline System::Void DirectedGraphNode::MinWidthSpecified::set(System::Boolean value) {
    this->minWidthFieldSpecified = value;
}

inline System::Double DirectedGraphNode::MaxWidth::get() {
    return this->maxWidthField;
}
inline System::Void DirectedGraphNode::MaxWidth::set(System::Double value) {
    this->maxWidthField = value;
}

inline System::Boolean DirectedGraphNode::MaxWidthSpecified::get() {
    return this->maxWidthFieldSpecified;
}
inline System::Void DirectedGraphNode::MaxWidthSpecified::set(System::Boolean value) {
    this->maxWidthFieldSpecified = value;
}

inline System::Double DirectedGraphNode::NodeRadius::get() {
    return this->nodeRadiusField;
}
inline System::Void DirectedGraphNode::NodeRadius::set(System::Double value) {
    this->nodeRadiusField = value;
}

inline System::Boolean DirectedGraphNode::NodeRadiusSpecified::get() {
    return this->nodeRadiusFieldSpecified;
}
inline System::Void DirectedGraphNode::NodeRadiusSpecified::set(System::Boolean value) {
    this->nodeRadiusFieldSpecified = value;
}

inline System::String^ DirectedGraphNode::Description::get() {
    return this->descriptionField;
}
inline System::Void DirectedGraphNode::Description::set(System::String^ value) {
    this->descriptionField = value;
}

inline GroupEnum DirectedGraphNode::Group::get() {
    return this->groupField;
}
inline System::Void DirectedGraphNode::Group::set(GroupEnum value) {
    this->groupField = value;
}

inline System::Boolean DirectedGraphNode::GroupSpecified::get() {
    return this->groupFieldSpecified;
}
inline System::Void DirectedGraphNode::GroupSpecified::set(System::Boolean value) {
    this->groupFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::IsVertical::get() {
    return this->isVerticalField;
}
inline System::Void DirectedGraphNode::IsVertical::set(ClrBoolean value) {
    this->isVerticalField = value;
}

inline System::Boolean DirectedGraphNode::IsVerticalSpecified::get() {
    return this->isVerticalFieldSpecified;
}
inline System::Void DirectedGraphNode::IsVerticalSpecified::set(System::Boolean value) {
    this->isVerticalFieldSpecified = value;
}

inline System::String^ DirectedGraphNode::Reference::get() {
    return this->referenceField;
}
inline System::Void DirectedGraphNode::Reference::set(System::String^ value) {
    this->referenceField = value;
}

inline System::String^ DirectedGraphNode::Label::get() {
    return this->labelField;
}
inline System::Void DirectedGraphNode::Label::set(System::String^ value) {
    this->labelField = value;
}

inline VisibilityEnum DirectedGraphNode::Visibility::get() {
    return this->visibilityField;
}
inline System::Void DirectedGraphNode::Visibility::set(VisibilityEnum value) {
    this->visibilityField = value;
}

inline System::Boolean DirectedGraphNode::VisibilitySpecified::get() {
    return this->visibilityFieldSpecified;
}
inline System::Void DirectedGraphNode::VisibilitySpecified::set(System::Boolean value) {
    this->visibilityFieldSpecified = value;
}

inline System::String^ DirectedGraphNode::Background::get() {
    return this->backgroundField;
}
inline System::Void DirectedGraphNode::Background::set(System::String^ value) {
    this->backgroundField = value;
}

inline System::Double DirectedGraphNode::FontSize::get() {
    return this->fontSizeField;
}
inline System::Void DirectedGraphNode::FontSize::set(System::Double value) {
    this->fontSizeField = value;
}

inline System::Boolean DirectedGraphNode::FontSizeSpecified::get() {
    return this->fontSizeFieldSpecified;
}
inline System::Void DirectedGraphNode::FontSizeSpecified::set(System::Boolean value) {
    this->fontSizeFieldSpecified = value;
}

inline System::String^ DirectedGraphNode::FontFamily::get() {
    return this->fontFamilyField;
}
inline System::Void DirectedGraphNode::FontFamily::set(System::String^ value) {
    this->fontFamilyField = value;
}

inline FontStyleEnum DirectedGraphNode::FontStyle::get() {
    return this->fontStyleField;
}
inline System::Void DirectedGraphNode::FontStyle::set(FontStyleEnum value) {
    this->fontStyleField = value;
}

inline System::Boolean DirectedGraphNode::FontStyleSpecified::get() {
    return this->fontStyleFieldSpecified;
}
inline System::Void DirectedGraphNode::FontStyleSpecified::set(System::Boolean value) {
    this->fontStyleFieldSpecified = value;
}

inline FontWeightEnum DirectedGraphNode::FontWeight::get() {
    return this->fontWeightField;
}
inline System::Void DirectedGraphNode::FontWeight::set(FontWeightEnum value) {
    this->fontWeightField = value;
}

inline System::Boolean DirectedGraphNode::FontWeightSpecified::get() {
    return this->fontWeightFieldSpecified;
}
inline System::Void DirectedGraphNode::FontWeightSpecified::set(System::Boolean value) {
    this->fontWeightFieldSpecified = value;
}

inline System::String^ DirectedGraphNode::Stroke::get() {
    return this->strokeField;
}
inline System::Void DirectedGraphNode::Stroke::set(System::String^ value) {
    this->strokeField = value;
}

inline System::String^ DirectedGraphNode::StrokeThickness::get() {
    return this->strokeThicknessField;
}
inline System::Void DirectedGraphNode::StrokeThickness::set(System::String^ value) {
    this->strokeThicknessField = value;
}

inline System::String^ DirectedGraphNode::StrokeDashArray::get() {
    return this->strokeDashArrayField;
}
inline System::Void DirectedGraphNode::StrokeDashArray::set(System::String^ value) {
    this->strokeDashArrayField = value;
}

inline System::String^ DirectedGraphNode::Access::get() {
    return this->accessField;
}
inline System::Void DirectedGraphNode::Access::set(System::String^ value) {
    this->accessField = value;
}

inline System::String^ DirectedGraphNode::Assembly::get() {
    return this->assemblyField;
}
inline System::Void DirectedGraphNode::Assembly::set(System::String^ value) {
    this->assemblyField = value;
}

inline System::String^ DirectedGraphNode::FilePath::get() {
    return this->filePathField;
}
inline System::Void DirectedGraphNode::FilePath::set(System::String^ value) {
    this->filePathField = value;
}

inline System::String^ DirectedGraphNode::FunctionTypeFlags::get() {
    return this->functionTypeFlagsField;
}
inline System::Void DirectedGraphNode::FunctionTypeFlags::set(System::String^ value) {
    this->functionTypeFlagsField = value;
}

inline ClrBoolean DirectedGraphNode::IsAbstract::get() {
    return this->isAbstractField;
}
inline System::Void DirectedGraphNode::IsAbstract::set(ClrBoolean value) {
    this->isAbstractField = value;
}

inline System::Boolean DirectedGraphNode::IsAbstractSpecified::get() {
    return this->isAbstractFieldSpecified;
}
inline System::Void DirectedGraphNode::IsAbstractSpecified::set(System::Boolean value) {
    this->isAbstractFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::IsCodeType::get() {
    return this->isCodeTypeField;
}
inline System::Void DirectedGraphNode::IsCodeType::set(ClrBoolean value) {
    this->isCodeTypeField = value;
}

inline System::Boolean DirectedGraphNode::IsCodeTypeSpecified::get() {
    return this->isCodeTypeFieldSpecified;
}
inline System::Void DirectedGraphNode::IsCodeTypeSpecified::set(System::Boolean value) {
    this->isCodeTypeFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::IsHub::get() {
    return this->isHubField;
}
inline System::Void DirectedGraphNode::IsHub::set(ClrBoolean value) {
    this->isHubField = value;
}

inline System::Boolean DirectedGraphNode::IsHubSpecified::get() {
    return this->isHubFieldSpecified;
}
inline System::Void DirectedGraphNode::IsHubSpecified::set(System::Boolean value) {
    this->isHubFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::IsOverloaded::get() {
    return this->isOverloadedField;
}
inline System::Void DirectedGraphNode::IsOverloaded::set(ClrBoolean value) {
    this->isOverloadedField = value;
}

inline System::Boolean DirectedGraphNode::IsOverloadedSpecified::get() {
    return this->isOverloadedFieldSpecified;
}
inline System::Void DirectedGraphNode::IsOverloadedSpecified::set(System::Boolean value) {
    this->isOverloadedFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::IsOverridable::get() {
    return this->isOverridableField;
}
inline System::Void DirectedGraphNode::IsOverridable::set(ClrBoolean value) {
    this->isOverridableField = value;
}

inline System::Boolean DirectedGraphNode::IsOverridableSpecified::get() {
    return this->isOverridableFieldSpecified;
}
inline System::Void DirectedGraphNode::IsOverridableSpecified::set(System::Boolean value) {
    this->isOverridableFieldSpecified = value;
}

inline System::String^ DirectedGraphNode::Language::get() {
    return this->languageField;
}
inline System::Void DirectedGraphNode::Language::set(System::String^ value) {
    this->languageField = value;
}

inline System::String^ DirectedGraphNode::Location::get() {
    return this->locationField;
}
inline System::Void DirectedGraphNode::Location::set(System::String^ value) {
    this->locationField = value;
}

inline System::Int32 DirectedGraphNode::LinesOfCode::get() {
    return this->linesOfCodeField;
}
inline System::Void DirectedGraphNode::LinesOfCode::set(System::Int32 value) {
    this->linesOfCodeField = value;
}

inline System::Boolean DirectedGraphNode::LinesOfCodeSpecified::get() {
    return this->linesOfCodeFieldSpecified;
}
inline System::Void DirectedGraphNode::LinesOfCodeSpecified::set(System::Boolean value) {
    this->linesOfCodeFieldSpecified = value;
}

inline System::String^ DirectedGraphNode::Namespace::get() {
    return this->namespaceField;
}
inline System::Void DirectedGraphNode::Namespace::set(System::String^ value) {
    this->namespaceField = value;
}

inline System::String^ DirectedGraphNode::MustImplement::get() {
    return this->mustImplementField;
}
inline System::Void DirectedGraphNode::MustImplement::set(System::String^ value) {
    this->mustImplementField = value;
}

inline System::String^ DirectedGraphNode::TypeName::get() {
    return this->typeNameField;
}
inline System::Void DirectedGraphNode::TypeName::set(System::String^ value) {
    this->typeNameField = value;
}

inline ClrBoolean DirectedGraphNode::IsDocumentation::get() {
    return this->isDocumentationField;
}
inline System::Void DirectedGraphNode::IsDocumentation::set(ClrBoolean value) {
    this->isDocumentationField = value;
}

inline System::Boolean DirectedGraphNode::IsDocumentationSpecified::get() {
    return this->isDocumentationFieldSpecified;
}
inline System::Void DirectedGraphNode::IsDocumentationSpecified::set(System::Boolean value) {
    this->isDocumentationFieldSpecified = value;
}

inline System::String^ DirectedGraphNode::CodeGenSourceName::get() {
    return this->codeGenSourceNameField;
}
inline System::Void DirectedGraphNode::CodeGenSourceName::set(System::String^ value) {
    this->codeGenSourceNameField = value;
}

inline System::String^ DirectedGraphNode::CodeGenTargetName::get() {
    return this->codeGenTargetNameField;
}
inline System::Void DirectedGraphNode::CodeGenTargetName::set(System::String^ value) {
    this->codeGenTargetNameField = value;
}

inline ClrBoolean DirectedGraphNode::CodeGenIncoming::get() {
    return this->codeGenIncomingField;
}
inline System::Void DirectedGraphNode::CodeGenIncoming::set(ClrBoolean value) {
    this->codeGenIncomingField = value;
}

inline System::Boolean DirectedGraphNode::CodeGenIncomingSpecified::get() {
    return this->codeGenIncomingFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeGenIncomingSpecified::set(System::Boolean value) {
    this->codeGenIncomingFieldSpecified = value;
}

inline System::Int32 DirectedGraphNode::CodeSchemaProperty_CallSequenceNumber::get() {
    return this->codeSchemaProperty_CallSequenceNumberField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_CallSequenceNumber::set(System::Int32 value) {
    this->codeSchemaProperty_CallSequenceNumberField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_CallSequenceNumberSpecified::get() {
    return this->codeSchemaProperty_CallSequenceNumberFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_CallSequenceNumberSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_CallSequenceNumberFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_DisableEnabledErrorHandler::get() {
    return this->codeSchemaProperty_DisableEnabledErrorHandlerField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_DisableEnabledErrorHandler::set(ClrBoolean value) {
    this->codeSchemaProperty_DisableEnabledErrorHandlerField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_DisableEnabledErrorHandlerSpecified::get() {
    return this->codeSchemaProperty_DisableEnabledErrorHandlerFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_DisableEnabledErrorHandlerSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_DisableEnabledErrorHandlerFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_DisableEnabledException::get() {
    return this->codeSchemaProperty_DisableEnabledExceptionField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_DisableEnabledException::set(ClrBoolean value) {
    this->codeSchemaProperty_DisableEnabledExceptionField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_DisableEnabledExceptionSpecified::get() {
    return this->codeSchemaProperty_DisableEnabledExceptionFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_DisableEnabledExceptionSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_DisableEnabledExceptionFieldSpecified = value;
}

inline System::Int32 DirectedGraphNode::CodeSchemaProperty_EndColumn::get() {
    return this->codeSchemaProperty_EndColumnField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_EndColumn::set(System::Int32 value) {
    this->codeSchemaProperty_EndColumnField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_EndColumnSpecified::get() {
    return this->codeSchemaProperty_EndColumnFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_EndColumnSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_EndColumnFieldSpecified = value;
}

inline System::Int32 DirectedGraphNode::CodeSchemaProperty_EndLine::get() {
    return this->codeSchemaProperty_EndLineField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_EndLine::set(System::Int32 value) {
    this->codeSchemaProperty_EndLineField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_EndLineSpecified::get() {
    return this->codeSchemaProperty_EndLineFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_EndLineSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_EndLineFieldSpecified = value;
}

inline System::Int32 DirectedGraphNode::CodeSchemaProperty_FrameDepth::get() {
    return this->codeSchemaProperty_FrameDepthField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_FrameDepth::set(System::Int32 value) {
    this->codeSchemaProperty_FrameDepthField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_FrameDepthSpecified::get() {
    return this->codeSchemaProperty_FrameDepthFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_FrameDepthSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_FrameDepthFieldSpecified = value;
}

inline FrameKindEnum DirectedGraphNode::CodeSchemaProperty_FrameKind::get() {
    return this->codeSchemaProperty_FrameKindField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_FrameKind::set(FrameKindEnum value) {
    this->codeSchemaProperty_FrameKindField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_FrameKindSpecified::get() {
    return this->codeSchemaProperty_FrameKindFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_FrameKindSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_FrameKindFieldSpecified = value;
}

inline System::String^ DirectedGraphNode::CodeSchemaProperty_Icon::get() {
    return this->codeSchemaProperty_IconField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_Icon::set(System::String^ value) {
    this->codeSchemaProperty_IconField = value;
}

inline System::String^ DirectedGraphNode::CodeSchemaProperty_InstanceTrackingInformation::get() {
    return this->codeSchemaProperty_InstanceTrackingInformationField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_InstanceTrackingInformation::set(System::String^ value) {
    this->codeSchemaProperty_InstanceTrackingInformationField = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsAbstract::get() {
    return this->codeSchemaProperty_IsAbstractField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsAbstract::set(ClrBoolean value) {
    this->codeSchemaProperty_IsAbstractField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsAbstractSpecified::get() {
    return this->codeSchemaProperty_IsAbstractFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsAbstractSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsAbstractFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsAnonymous::get() {
    return this->codeSchemaProperty_IsAnonymousField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsAnonymous::set(ClrBoolean value) {
    this->codeSchemaProperty_IsAnonymousField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsAnonymousSpecified::get() {
    return this->codeSchemaProperty_IsAnonymousFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsAnonymousSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsAnonymousFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsArray::get() {
    return this->codeSchemaProperty_IsArrayField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsArray::set(ClrBoolean value) {
    this->codeSchemaProperty_IsArrayField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsArraySpecified::get() {
    return this->codeSchemaProperty_IsArrayFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsArraySpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsArrayFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsByReference::get() {
    return this->codeSchemaProperty_IsByReferenceField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsByReference::set(ClrBoolean value) {
    this->codeSchemaProperty_IsByReferenceField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsByReferenceSpecified::get() {
    return this->codeSchemaProperty_IsByReferenceFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsByReferenceSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsByReferenceFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsCallToThis::get() {
    return this->codeSchemaProperty_IsCallToThisField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsCallToThis::set(ClrBoolean value) {
    this->codeSchemaProperty_IsCallToThisField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsCallToThisSpecified::get() {
    return this->codeSchemaProperty_IsCallToThisFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsCallToThisSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsCallToThisFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsConstructor::get() {
    return this->codeSchemaProperty_IsConstructorField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsConstructor::set(ClrBoolean value) {
    this->codeSchemaProperty_IsConstructorField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsConstructorSpecified::get() {
    return this->codeSchemaProperty_IsConstructorFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsConstructorSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsConstructorFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsDo::get() {
    return this->codeSchemaProperty_IsDoField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsDo::set(ClrBoolean value) {
    this->codeSchemaProperty_IsDoField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsDoSpecified::get() {
    return this->codeSchemaProperty_IsDoFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsDoSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsDoFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsFinal::get() {
    return this->codeSchemaProperty_IsFinalField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsFinal::set(ClrBoolean value) {
    this->codeSchemaProperty_IsFinalField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsFinalSpecified::get() {
    return this->codeSchemaProperty_IsFinalFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsFinalSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsFinalFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsFor::get() {
    return this->codeSchemaProperty_IsForField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsFor::set(ClrBoolean value) {
    this->codeSchemaProperty_IsForField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsForSpecified::get() {
    return this->codeSchemaProperty_IsForFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsForSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsForFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsForEach::get() {
    return this->codeSchemaProperty_IsForEachField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsForEach::set(ClrBoolean value) {
    this->codeSchemaProperty_IsForEachField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsForEachSpecified::get() {
    return this->codeSchemaProperty_IsForEachFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsForEachSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsForEachFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsGeneric::get() {
    return this->codeSchemaProperty_IsGenericField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsGeneric::set(ClrBoolean value) {
    this->codeSchemaProperty_IsGenericField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsGenericSpecified::get() {
    return this->codeSchemaProperty_IsGenericFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsGenericSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsGenericFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsGenericInstance::get() {
    return this->codeSchemaProperty_IsGenericInstanceField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsGenericInstance::set(ClrBoolean value) {
    this->codeSchemaProperty_IsGenericInstanceField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsGenericInstanceSpecified::get() {
    return this->codeSchemaProperty_IsGenericInstanceFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsGenericInstanceSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsGenericInstanceFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsInternal::get() {
    return this->codeSchemaProperty_IsInternalField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsInternal::set(ClrBoolean value) {
    this->codeSchemaProperty_IsInternalField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsInternalSpecified::get() {
    return this->codeSchemaProperty_IsInternalFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsInternalSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsInternalFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsHideBySignature::get() {
    return this->codeSchemaProperty_IsHideBySignatureField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsHideBySignature::set(ClrBoolean value) {
    this->codeSchemaProperty_IsHideBySignatureField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsHideBySignatureSpecified::get() {
    return this->codeSchemaProperty_IsHideBySignatureFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsHideBySignatureSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsHideBySignatureFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsOperator::get() {
    return this->codeSchemaProperty_IsOperatorField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsOperator::set(ClrBoolean value) {
    this->codeSchemaProperty_IsOperatorField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsOperatorSpecified::get() {
    return this->codeSchemaProperty_IsOperatorFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsOperatorSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsOperatorFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsOut::get() {
    return this->codeSchemaProperty_IsOutField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsOut::set(ClrBoolean value) {
    this->codeSchemaProperty_IsOutField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsOutSpecified::get() {
    return this->codeSchemaProperty_IsOutFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsOutSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsOutFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsParameterArray::get() {
    return this->codeSchemaProperty_IsParameterArrayField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsParameterArray::set(ClrBoolean value) {
    this->codeSchemaProperty_IsParameterArrayField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsParameterArraySpecified::get() {
    return this->codeSchemaProperty_IsParameterArrayFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsParameterArraySpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsParameterArrayFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsPrivate::get() {
    return this->codeSchemaProperty_IsPrivateField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsPrivate::set(ClrBoolean value) {
    this->codeSchemaProperty_IsPrivateField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsPrivateSpecified::get() {
    return this->codeSchemaProperty_IsPrivateFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsPrivateSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsPrivateFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsProtected::get() {
    return this->codeSchemaProperty_IsProtectedField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsProtected::set(ClrBoolean value) {
    this->codeSchemaProperty_IsProtectedField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsProtectedSpecified::get() {
    return this->codeSchemaProperty_IsProtectedFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsProtectedSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsProtectedFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsProtectedOrInternal::get() {
    return this->codeSchemaProperty_IsProtectedOrInternalField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsProtectedOrInternal::set(ClrBoolean value) {
    this->codeSchemaProperty_IsProtectedOrInternalField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsProtectedOrInternalSpecified::get() {
    return this->codeSchemaProperty_IsProtectedOrInternalFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsProtectedOrInternalSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsProtectedOrInternalFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsPropertyGet::get() {
    return this->codeSchemaProperty_IsPropertyGetField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsPropertyGet::set(ClrBoolean value) {
    this->codeSchemaProperty_IsPropertyGetField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsPropertyGetSpecified::get() {
    return this->codeSchemaProperty_IsPropertyGetFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsPropertyGetSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsPropertyGetFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsPropertySet::get() {
    return this->codeSchemaProperty_IsPropertySetField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsPropertySet::set(ClrBoolean value) {
    this->codeSchemaProperty_IsPropertySetField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsPropertySetSpecified::get() {
    return this->codeSchemaProperty_IsPropertySetFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsPropertySetSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsPropertySetFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsPrototype::get() {
    return this->codeSchemaProperty_IsPrototypeField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsPrototype::set(ClrBoolean value) {
    this->codeSchemaProperty_IsPrototypeField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsPrototypeSpecified::get() {
    return this->codeSchemaProperty_IsPrototypeFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsPrototypeSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsPrototypeFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsPublic::get() {
    return this->codeSchemaProperty_IsPublicField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsPublic::set(ClrBoolean value) {
    this->codeSchemaProperty_IsPublicField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsPublicSpecified::get() {
    return this->codeSchemaProperty_IsPublicFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsPublicSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsPublicFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsSpecialName::get() {
    return this->codeSchemaProperty_IsSpecialNameField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsSpecialName::set(ClrBoolean value) {
    this->codeSchemaProperty_IsSpecialNameField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsSpecialNameSpecified::get() {
    return this->codeSchemaProperty_IsSpecialNameFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsSpecialNameSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsSpecialNameFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsStatic::get() {
    return this->codeSchemaProperty_IsStaticField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsStatic::set(ClrBoolean value) {
    this->codeSchemaProperty_IsStaticField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsStaticSpecified::get() {
    return this->codeSchemaProperty_IsStaticFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsStaticSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsStaticFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsUntilLoop::get() {
    return this->codeSchemaProperty_IsUntilLoopField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsUntilLoop::set(ClrBoolean value) {
    this->codeSchemaProperty_IsUntilLoopField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsUntilLoopSpecified::get() {
    return this->codeSchemaProperty_IsUntilLoopFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsUntilLoopSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsUntilLoopFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsVirtual::get() {
    return this->codeSchemaProperty_IsVirtualField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsVirtual::set(ClrBoolean value) {
    this->codeSchemaProperty_IsVirtualField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsVirtualSpecified::get() {
    return this->codeSchemaProperty_IsVirtualFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsVirtualSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsVirtualFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_IsWhile::get() {
    return this->codeSchemaProperty_IsWhileField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsWhile::set(ClrBoolean value) {
    this->codeSchemaProperty_IsWhileField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_IsWhileSpecified::get() {
    return this->codeSchemaProperty_IsWhileFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_IsWhileSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_IsWhileFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_PreserveData::get() {
    return this->codeSchemaProperty_PreserveDataField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_PreserveData::set(ClrBoolean value) {
    this->codeSchemaProperty_PreserveDataField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_PreserveDataSpecified::get() {
    return this->codeSchemaProperty_PreserveDataFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_PreserveDataSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_PreserveDataFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_SingleInstanceSourceLink::get() {
    return this->codeSchemaProperty_SingleInstanceSourceLinkField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_SingleInstanceSourceLink::set(ClrBoolean value) {
    this->codeSchemaProperty_SingleInstanceSourceLinkField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_SingleInstanceSourceLinkSpecified::get() {
    return this->codeSchemaProperty_SingleInstanceSourceLinkFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_SingleInstanceSourceLinkSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_SingleInstanceSourceLinkFieldSpecified = value;
}

inline ClrBoolean DirectedGraphNode::CodeSchemaProperty_SingleInstanceTargetLink::get() {
    return this->codeSchemaProperty_SingleInstanceTargetLinkField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_SingleInstanceTargetLink::set(ClrBoolean value) {
    this->codeSchemaProperty_SingleInstanceTargetLinkField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_SingleInstanceTargetLinkSpecified::get() {
    return this->codeSchemaProperty_SingleInstanceTargetLinkFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_SingleInstanceTargetLinkSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_SingleInstanceTargetLinkFieldSpecified = value;
}

inline System::String^ DirectedGraphNode::CodeSchemaProperty_SourceText::get() {
    return this->codeSchemaProperty_SourceTextField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_SourceText::set(System::String^ value) {
    this->codeSchemaProperty_SourceTextField = value;
}

inline System::Int32 DirectedGraphNode::CodeSchemaProperty_StartColumn::get() {
    return this->codeSchemaProperty_StartColumnField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_StartColumn::set(System::Int32 value) {
    this->codeSchemaProperty_StartColumnField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_StartColumnSpecified::get() {
    return this->codeSchemaProperty_StartColumnFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_StartColumnSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_StartColumnFieldSpecified = value;
}

inline System::Int32 DirectedGraphNode::CodeSchemaProperty_StartLine::get() {
    return this->codeSchemaProperty_StartLineField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_StartLine::set(System::Int32 value) {
    this->codeSchemaProperty_StartLineField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_StartLineSpecified::get() {
    return this->codeSchemaProperty_StartLineFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_StartLineSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_StartLineFieldSpecified = value;
}

inline System::String^ DirectedGraphNode::CodeSchemaProperty_StatementKind::get() {
    return this->codeSchemaProperty_StatementKindField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_StatementKind::set(System::String^ value) {
    this->codeSchemaProperty_StatementKindField = value;
}

inline System::Int32 DirectedGraphNode::CodeSchemaProperty_StatementNumber::get() {
    return this->codeSchemaProperty_StatementNumberField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_StatementNumber::set(System::Int32 value) {
    this->codeSchemaProperty_StatementNumberField = value;
}

inline System::Boolean DirectedGraphNode::CodeSchemaProperty_StatementNumberSpecified::get() {
    return this->codeSchemaProperty_StatementNumberFieldSpecified;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_StatementNumberSpecified::set(System::Boolean value) {
    this->codeSchemaProperty_StatementNumberFieldSpecified = value;
}

inline System::String^ DirectedGraphNode::CodeSchemaProperty_StatementType::get() {
    return this->codeSchemaProperty_StatementTypeField;
}
inline System::Void DirectedGraphNode::CodeSchemaProperty_StatementType::set(System::String^ value) {
    this->codeSchemaProperty_StatementTypeField = value;
}


inline System::String^ DirectedGraphNodeCategory::Ref::get() {
    return this->refField;
}
inline System::Void DirectedGraphNodeCategory::Ref::set(System::String^ value) {
    this->refField = value;
}


inline cli::array< DirectedGraphLinkCategory^  >^ DirectedGraphLink::Category::get() {
    return this->categoryField;
}
inline System::Void DirectedGraphLink::Category::set(cli::array< DirectedGraphLinkCategory^  >^ value) {
    this->categoryField = value;
}

inline System::String^ DirectedGraphLink::Label::get() {
    return this->labelField;
}
inline System::Void DirectedGraphLink::Label::set(System::String^ value) {
    this->labelField = value;
}

inline VisibilityEnum DirectedGraphLink::Visibility::get() {
    return this->visibilityField;
}
inline System::Void DirectedGraphLink::Visibility::set(VisibilityEnum value) {
    this->visibilityField = value;
}

inline System::Boolean DirectedGraphLink::VisibilitySpecified::get() {
    return this->visibilityFieldSpecified;
}
inline System::Void DirectedGraphLink::VisibilitySpecified::set(System::Boolean value) {
    this->visibilityFieldSpecified = value;
}

inline System::String^ DirectedGraphLink::Background::get() {
    return this->backgroundField;
}
inline System::Void DirectedGraphLink::Background::set(System::String^ value) {
    this->backgroundField = value;
}

inline System::Double DirectedGraphLink::FontSize::get() {
    return this->fontSizeField;
}
inline System::Void DirectedGraphLink::FontSize::set(System::Double value) {
    this->fontSizeField = value;
}

inline System::Boolean DirectedGraphLink::FontSizeSpecified::get() {
    return this->fontSizeFieldSpecified;
}
inline System::Void DirectedGraphLink::FontSizeSpecified::set(System::Boolean value) {
    this->fontSizeFieldSpecified = value;
}

inline System::String^ DirectedGraphLink::FontFamily::get() {
    return this->fontFamilyField;
}
inline System::Void DirectedGraphLink::FontFamily::set(System::String^ value) {
    this->fontFamilyField = value;
}

inline FontStyleEnum DirectedGraphLink::FontStyle::get() {
    return this->fontStyleField;
}
inline System::Void DirectedGraphLink::FontStyle::set(FontStyleEnum value) {
    this->fontStyleField = value;
}

inline System::Boolean DirectedGraphLink::FontStyleSpecified::get() {
    return this->fontStyleFieldSpecified;
}
inline System::Void DirectedGraphLink::FontStyleSpecified::set(System::Boolean value) {
    this->fontStyleFieldSpecified = value;
}

inline FontWeightEnum DirectedGraphLink::FontWeight::get() {
    return this->fontWeightField;
}
inline System::Void DirectedGraphLink::FontWeight::set(FontWeightEnum value) {
    this->fontWeightField = value;
}

inline System::Boolean DirectedGraphLink::FontWeightSpecified::get() {
    return this->fontWeightFieldSpecified;
}
inline System::Void DirectedGraphLink::FontWeightSpecified::set(System::Boolean value) {
    this->fontWeightFieldSpecified = value;
}

inline System::String^ DirectedGraphLink::Stroke::get() {
    return this->strokeField;
}
inline System::Void DirectedGraphLink::Stroke::set(System::String^ value) {
    this->strokeField = value;
}

inline System::String^ DirectedGraphLink::StrokeThickness::get() {
    return this->strokeThicknessField;
}
inline System::Void DirectedGraphLink::StrokeThickness::set(System::String^ value) {
    this->strokeThicknessField = value;
}

inline System::String^ DirectedGraphLink::StrokeDashArray::get() {
    return this->strokeDashArrayField;
}
inline System::Void DirectedGraphLink::StrokeDashArray::set(System::String^ value) {
    this->strokeDashArrayField = value;
}

inline System::String^ DirectedGraphLink::Source::get() {
    return this->sourceField;
}
inline System::Void DirectedGraphLink::Source::set(System::String^ value) {
    this->sourceField = value;
}

inline System::String^ DirectedGraphLink::Target::get() {
    return this->targetField;
}
inline System::Void DirectedGraphLink::Target::set(System::String^ value) {
    this->targetField = value;
}

inline System::String^ DirectedGraphLink::Category1::get() {
    return this->category1Field;
}
inline System::Void DirectedGraphLink::Category1::set(System::String^ value) {
    this->category1Field = value;
}

inline ClrBoolean DirectedGraphLink::Seeder::get() {
    return this->seederField;
}
inline System::Void DirectedGraphLink::Seeder::set(ClrBoolean value) {
    this->seederField = value;
}

inline System::Boolean DirectedGraphLink::SeederSpecified::get() {
    return this->seederFieldSpecified;
}
inline System::Void DirectedGraphLink::SeederSpecified::set(System::Boolean value) {
    this->seederFieldSpecified = value;
}

inline ClrBoolean DirectedGraphLink::AttractConsumers::get() {
    return this->attractConsumersField;
}
inline System::Void DirectedGraphLink::AttractConsumers::set(ClrBoolean value) {
    this->attractConsumersField = value;
}

inline System::Boolean DirectedGraphLink::AttractConsumersSpecified::get() {
    return this->attractConsumersFieldSpecified;
}
inline System::Void DirectedGraphLink::AttractConsumersSpecified::set(System::Boolean value) {
    this->attractConsumersFieldSpecified = value;
}


inline System::String^ DirectedGraphLinkCategory::Ref::get() {
    return this->refField;
}
inline System::Void DirectedGraphLinkCategory::Ref::set(System::String^ value) {
    this->refField = value;
}


inline System::String^ DirectedGraphCategory::Id::get() {
    return this->idField;
}
inline System::Void DirectedGraphCategory::Id::set(System::String^ value) {
    this->idField = value;
}

inline System::String^ DirectedGraphCategory::BasedOn::get() {
    return this->basedOnField;
}
inline System::Void DirectedGraphCategory::BasedOn::set(System::String^ value) {
    this->basedOnField = value;
}

inline System::String^ DirectedGraphCategory::Label::get() {
    return this->labelField;
}
inline System::Void DirectedGraphCategory::Label::set(System::String^ value) {
    this->labelField = value;
}

inline VisibilityEnum DirectedGraphCategory::Visibility::get() {
    return this->visibilityField;
}
inline System::Void DirectedGraphCategory::Visibility::set(VisibilityEnum value) {
    this->visibilityField = value;
}

inline System::Boolean DirectedGraphCategory::VisibilitySpecified::get() {
    return this->visibilityFieldSpecified;
}
inline System::Void DirectedGraphCategory::VisibilitySpecified::set(System::Boolean value) {
    this->visibilityFieldSpecified = value;
}

inline System::String^ DirectedGraphCategory::Background::get() {
    return this->backgroundField;
}
inline System::Void DirectedGraphCategory::Background::set(System::String^ value) {
    this->backgroundField = value;
}

inline System::Double DirectedGraphCategory::FontSize::get() {
    return this->fontSizeField;
}
inline System::Void DirectedGraphCategory::FontSize::set(System::Double value) {
    this->fontSizeField = value;
}

inline System::Boolean DirectedGraphCategory::FontSizeSpecified::get() {
    return this->fontSizeFieldSpecified;
}
inline System::Void DirectedGraphCategory::FontSizeSpecified::set(System::Boolean value) {
    this->fontSizeFieldSpecified = value;
}

inline System::String^ DirectedGraphCategory::FontFamily::get() {
    return this->fontFamilyField;
}
inline System::Void DirectedGraphCategory::FontFamily::set(System::String^ value) {
    this->fontFamilyField = value;
}

inline FontStyleEnum DirectedGraphCategory::FontStyle::get() {
    return this->fontStyleField;
}
inline System::Void DirectedGraphCategory::FontStyle::set(FontStyleEnum value) {
    this->fontStyleField = value;
}

inline System::Boolean DirectedGraphCategory::FontStyleSpecified::get() {
    return this->fontStyleFieldSpecified;
}
inline System::Void DirectedGraphCategory::FontStyleSpecified::set(System::Boolean value) {
    this->fontStyleFieldSpecified = value;
}

inline FontWeightEnum DirectedGraphCategory::FontWeight::get() {
    return this->fontWeightField;
}
inline System::Void DirectedGraphCategory::FontWeight::set(FontWeightEnum value) {
    this->fontWeightField = value;
}

inline System::Boolean DirectedGraphCategory::FontWeightSpecified::get() {
    return this->fontWeightFieldSpecified;
}
inline System::Void DirectedGraphCategory::FontWeightSpecified::set(System::Boolean value) {
    this->fontWeightFieldSpecified = value;
}

inline System::String^ DirectedGraphCategory::Stroke::get() {
    return this->strokeField;
}
inline System::Void DirectedGraphCategory::Stroke::set(System::String^ value) {
    this->strokeField = value;
}

inline System::String^ DirectedGraphCategory::StrokeThickness::get() {
    return this->strokeThicknessField;
}
inline System::Void DirectedGraphCategory::StrokeThickness::set(System::String^ value) {
    this->strokeThicknessField = value;
}

inline System::String^ DirectedGraphCategory::StrokeDashArray::get() {
    return this->strokeDashArrayField;
}
inline System::Void DirectedGraphCategory::StrokeDashArray::set(System::String^ value) {
    this->strokeDashArrayField = value;
}

inline System::String^ DirectedGraphCategory::Icon::get() {
    return this->iconField;
}
inline System::Void DirectedGraphCategory::Icon::set(System::String^ value) {
    this->iconField = value;
}

inline System::String^ DirectedGraphCategory::Shape::get() {
    return this->shapeField;
}
inline System::Void DirectedGraphCategory::Shape::set(System::String^ value) {
    this->shapeField = value;
}

inline System::String^ DirectedGraphCategory::Style::get() {
    return this->styleField;
}
inline System::Void DirectedGraphCategory::Style::set(System::String^ value) {
    this->styleField = value;
}

inline HorizontalAlignmentEnum DirectedGraphCategory::HorizontalAlignment::get() {
    return this->horizontalAlignmentField;
}
inline System::Void DirectedGraphCategory::HorizontalAlignment::set(HorizontalAlignmentEnum value) {
    this->horizontalAlignmentField = value;
}

inline System::Boolean DirectedGraphCategory::HorizontalAlignmentSpecified::get() {
    return this->horizontalAlignmentFieldSpecified;
}
inline System::Void DirectedGraphCategory::HorizontalAlignmentSpecified::set(System::Boolean value) {
    this->horizontalAlignmentFieldSpecified = value;
}

inline VerticalAlignmentEnum DirectedGraphCategory::VerticalAlignment::get() {
    return this->verticalAlignmentField;
}
inline System::Void DirectedGraphCategory::VerticalAlignment::set(VerticalAlignmentEnum value) {
    this->verticalAlignmentField = value;
}

inline System::Boolean DirectedGraphCategory::VerticalAlignmentSpecified::get() {
    return this->verticalAlignmentFieldSpecified;
}
inline System::Void DirectedGraphCategory::VerticalAlignmentSpecified::set(System::Boolean value) {
    this->verticalAlignmentFieldSpecified = value;
}

inline System::Double DirectedGraphCategory::MinWidth::get() {
    return this->minWidthField;
}
inline System::Void DirectedGraphCategory::MinWidth::set(System::Double value) {
    this->minWidthField = value;
}

inline System::Boolean DirectedGraphCategory::MinWidthSpecified::get() {
    return this->minWidthFieldSpecified;
}
inline System::Void DirectedGraphCategory::MinWidthSpecified::set(System::Boolean value) {
    this->minWidthFieldSpecified = value;
}

inline System::Double DirectedGraphCategory::MaxWidth::get() {
    return this->maxWidthField;
}
inline System::Void DirectedGraphCategory::MaxWidth::set(System::Double value) {
    this->maxWidthField = value;
}

inline System::Boolean DirectedGraphCategory::MaxWidthSpecified::get() {
    return this->maxWidthFieldSpecified;
}
inline System::Void DirectedGraphCategory::MaxWidthSpecified::set(System::Boolean value) {
    this->maxWidthFieldSpecified = value;
}

inline System::Double DirectedGraphCategory::NodeRadius::get() {
    return this->nodeRadiusField;
}
inline System::Void DirectedGraphCategory::NodeRadius::set(System::Double value) {
    this->nodeRadiusField = value;
}

inline System::Boolean DirectedGraphCategory::NodeRadiusSpecified::get() {
    return this->nodeRadiusFieldSpecified;
}
inline System::Void DirectedGraphCategory::NodeRadiusSpecified::set(System::Boolean value) {
    this->nodeRadiusFieldSpecified = value;
}

inline System::String^ DirectedGraphCategory::CanLinkedNodesBeDataDriven::get() {
    return this->canLinkedNodesBeDataDrivenField;
}
inline System::Void DirectedGraphCategory::CanLinkedNodesBeDataDriven::set(System::String^ value) {
    this->canLinkedNodesBeDataDrivenField = value;
}

inline System::String^ DirectedGraphCategory::CanBeDataDriven::get() {
    return this->canBeDataDrivenField;
}
inline System::Void DirectedGraphCategory::CanBeDataDriven::set(System::String^ value) {
    this->canBeDataDrivenField = value;
}

inline System::String^ DirectedGraphCategory::DefaultAction::get() {
    return this->defaultActionField;
}
inline System::Void DirectedGraphCategory::DefaultAction::set(System::String^ value) {
    this->defaultActionField = value;
}

inline System::String^ DirectedGraphCategory::IncomingActionLabel::get() {
    return this->incomingActionLabelField;
}
inline System::Void DirectedGraphCategory::IncomingActionLabel::set(System::String^ value) {
    this->incomingActionLabelField = value;
}

inline ClrBoolean DirectedGraphCategory::IsProviderRoot::get() {
    return this->isProviderRootField;
}
inline System::Void DirectedGraphCategory::IsProviderRoot::set(ClrBoolean value) {
    this->isProviderRootField = value;
}

inline System::Boolean DirectedGraphCategory::IsProviderRootSpecified::get() {
    return this->isProviderRootFieldSpecified;
}
inline System::Void DirectedGraphCategory::IsProviderRootSpecified::set(System::Boolean value) {
    this->isProviderRootFieldSpecified = value;
}

inline ClrBoolean DirectedGraphCategory::IsContainment::get() {
    return this->isContainmentField;
}
inline System::Void DirectedGraphCategory::IsContainment::set(ClrBoolean value) {
    this->isContainmentField = value;
}

inline System::Boolean DirectedGraphCategory::IsContainmentSpecified::get() {
    return this->isContainmentFieldSpecified;
}
inline System::Void DirectedGraphCategory::IsContainmentSpecified::set(System::Boolean value) {
    this->isContainmentFieldSpecified = value;
}

inline ClrBoolean DirectedGraphCategory::IsTag::get() {
    return this->isTagField;
}
inline System::Void DirectedGraphCategory::IsTag::set(ClrBoolean value) {
    this->isTagField = value;
}

inline System::Boolean DirectedGraphCategory::IsTagSpecified::get() {
    return this->isTagFieldSpecified;
}
inline System::Void DirectedGraphCategory::IsTagSpecified::set(System::Boolean value) {
    this->isTagFieldSpecified = value;
}

inline System::String^ DirectedGraphCategory::NavigationActionLabel::get() {
    return this->navigationActionLabelField;
}
inline System::Void DirectedGraphCategory::NavigationActionLabel::set(System::String^ value) {
    this->navigationActionLabelField = value;
}

inline System::String^ DirectedGraphCategory::OutgoingActionLabel::get() {
    return this->outgoingActionLabelField;
}
inline System::Void DirectedGraphCategory::OutgoingActionLabel::set(System::String^ value) {
    this->outgoingActionLabelField = value;
}

inline System::String^ DirectedGraphCategory::SourceCategory::get() {
    return this->sourceCategoryField;
}
inline System::Void DirectedGraphCategory::SourceCategory::set(System::String^ value) {
    this->sourceCategoryField = value;
}

inline System::String^ DirectedGraphCategory::TargetCategory::get() {
    return this->targetCategoryField;
}
inline System::Void DirectedGraphCategory::TargetCategory::set(System::String^ value) {
    this->targetCategoryField = value;
}

inline System::String^ DirectedGraphCategory::Details::get() {
    return this->detailsField;
}
inline System::Void DirectedGraphCategory::Details::set(System::String^ value) {
    this->detailsField = value;
}

inline System::String^ DirectedGraphCategory::InboundName::get() {
    return this->inboundNameField;
}
inline System::Void DirectedGraphCategory::InboundName::set(System::String^ value) {
    this->inboundNameField = value;
}

inline System::String^ DirectedGraphCategory::OutboundName::get() {
    return this->outboundNameField;
}
inline System::Void DirectedGraphCategory::OutboundName::set(System::String^ value) {
    this->outboundNameField = value;
}


inline System::String^ DirectedGraphProperty::Id::get() {
    return this->idField;
}
inline System::Void DirectedGraphProperty::Id::set(System::String^ value) {
    this->idField = value;
}

inline ClrBoolean DirectedGraphProperty::IsReference::get() {
    return this->isReferenceField;
}
inline System::Void DirectedGraphProperty::IsReference::set(ClrBoolean value) {
    this->isReferenceField = value;
}

inline System::Boolean DirectedGraphProperty::IsReferenceSpecified::get() {
    return this->isReferenceFieldSpecified;
}
inline System::Void DirectedGraphProperty::IsReferenceSpecified::set(System::Boolean value) {
    this->isReferenceFieldSpecified = value;
}

inline System::String^ DirectedGraphProperty::Label::get() {
    return this->labelField;
}
inline System::Void DirectedGraphProperty::Label::set(System::String^ value) {
    this->labelField = value;
}

inline System::String^ DirectedGraphProperty::DataType::get() {
    return this->dataTypeField;
}
inline System::Void DirectedGraphProperty::DataType::set(System::String^ value) {
    this->dataTypeField = value;
}

inline System::String^ DirectedGraphProperty::Description::get() {
    return this->descriptionField;
}
inline System::Void DirectedGraphProperty::Description::set(System::String^ value) {
    this->descriptionField = value;
}

inline System::String^ DirectedGraphProperty::Group::get() {
    return this->groupField;
}
inline System::Void DirectedGraphProperty::Group::set(System::String^ value) {
    this->groupField = value;
}

inline System::String^ DirectedGraphProperty::ReferenceTemplate::get() {
    return this->referenceTemplateField;
}
inline System::Void DirectedGraphProperty::ReferenceTemplate::set(System::String^ value) {
    this->referenceTemplateField = value;
}


inline System::String^ DirectedGraphName::Id::get() {
    return this->idField;
}
inline System::Void DirectedGraphName::Id::set(System::String^ value) {
    this->idField = value;
}

inline System::String^ DirectedGraphName::Label::get() {
    return this->labelField;
}
inline System::Void DirectedGraphName::Label::set(System::String^ value) {
    this->labelField = value;
}

inline System::String^ DirectedGraphName::ValueType::get() {
    return this->valueTypeField;
}
inline System::Void DirectedGraphName::ValueType::set(System::String^ value) {
    this->valueTypeField = value;
}

inline System::String^ DirectedGraphName::Formatter::get() {
    return this->formatterField;
}
inline System::Void DirectedGraphName::Formatter::set(System::String^ value) {
    this->formatterField = value;
}


inline System::Byte DirectedGraphAlias::n::get() {
    return this->nField;
}
inline System::Void DirectedGraphAlias::n::set(System::Byte value) {
    this->nField = value;
}

inline System::String^ DirectedGraphAlias::Uri::get() {
    return this->uriField;
}
inline System::Void DirectedGraphAlias::Uri::set(System::String^ value) {
    this->uriField = value;
}

inline System::String^ DirectedGraphAlias::Id::get() {
    return this->idField;
}
inline System::Void DirectedGraphAlias::Id::set(System::String^ value) {
    this->idField = value;
}


inline DirectedGraphStyleCondition^ DirectedGraphStyle::Condition::get() {
    return this->conditionField;
}
inline System::Void DirectedGraphStyle::Condition::set(DirectedGraphStyleCondition^ value) {
    this->conditionField = value;
}

inline cli::array< DirectedGraphStyleSetter^  >^ DirectedGraphStyle::Setter::get() {
    return this->setterField;
}
inline System::Void DirectedGraphStyle::Setter::set(cli::array< DirectedGraphStyleSetter^  >^ value) {
    this->setterField = value;
}

inline TargetTypeEnum DirectedGraphStyle::TargetType::get() {
    return this->targetTypeField;
}
inline System::Void DirectedGraphStyle::TargetType::set(TargetTypeEnum value) {
    this->targetTypeField = value;
}

inline ClrBoolean DirectedGraphStyle::IsEnabled::get() {
    return this->isEnabledField;
}
inline System::Void DirectedGraphStyle::IsEnabled::set(ClrBoolean value) {
    this->isEnabledField = value;
}

inline System::Boolean DirectedGraphStyle::IsEnabledSpecified::get() {
    return this->isEnabledFieldSpecified;
}
inline System::Void DirectedGraphStyle::IsEnabledSpecified::set(System::Boolean value) {
    this->isEnabledFieldSpecified = value;
}

inline System::String^ DirectedGraphStyle::GroupLabel::get() {
    return this->groupLabelField;
}
inline System::Void DirectedGraphStyle::GroupLabel::set(System::String^ value) {
    this->groupLabelField = value;
}

inline System::String^ DirectedGraphStyle::ValueLabel::get() {
    return this->valueLabelField;
}
inline System::Void DirectedGraphStyle::ValueLabel::set(System::String^ value) {
    this->valueLabelField = value;
}

inline System::String^ DirectedGraphStyle::ToolTip::get() {
    return this->toolTipField;
}
inline System::Void DirectedGraphStyle::ToolTip::set(System::String^ value) {
    this->toolTipField = value;
}


inline System::String^ DirectedGraphStyleCondition::Expression::get() {
    return this->expressionField;
}
inline System::Void DirectedGraphStyleCondition::Expression::set(System::String^ value) {
    this->expressionField = value;
}


inline PropertyType DirectedGraphStyleSetter::Property::get() {
    return this->propertyField;
}
inline System::Void DirectedGraphStyleSetter::Property::set(PropertyType value) {
    this->propertyField = value;
}

inline System::String^ DirectedGraphStyleSetter::Value::get() {
    return this->valueField;
}
inline System::Void DirectedGraphStyleSetter::Value::set(System::String^ value) {
    this->valueField = value;
}

inline System::String^ DirectedGraphStyleSetter::Expression::get() {
    return this->expressionField;
}
inline System::Void DirectedGraphStyleSetter::Expression::set(System::String^ value) {
    this->expressionField = value;
}


inline System::String^ DirectedGraphPath::Id::get() {
    return this->idField;
}
inline System::Void DirectedGraphPath::Id::set(System::String^ value) {
    this->idField = value;
}

inline System::String^ DirectedGraphPath::Value::get() {
    return this->valueField;
}
inline System::Void DirectedGraphPath::Value::set(System::String^ value) {
    this->valueField = value;
}
