// SPDX-FileCopyrightText: Fondazione Istituto Italiano di Tecnologia (IIT)
// SPDX-License-Identifier: BSD-3-Clause

#ifndef IDYNTREE_MODELIO_URDF_MATERIALELEMENT_H
#define IDYNTREE_MODELIO_URDF_MATERIALELEMENT_H

#include <iDynTree/XMLElement.h>

#include <iDynTree/Core/VectorFixSize.h>

#include <memory>
#include <string>


namespace iDynTree {
    class MaterialElement;

    class XMLAttribute;
    class XMLParserState;
}

class iDynTree::MaterialElement: public iDynTree::XMLElement
{
public:
    struct MaterialInfo {
        std::string m_name;
        std::string m_textureFilename;
        std::shared_ptr<iDynTree::Vector4> m_rgba; // This is optional, use a pointer
    };

private:
    std::shared_ptr<MaterialInfo> m_info;

public:
    explicit MaterialElement(
        XMLParserState& parserState, 
        std::shared_ptr<MaterialInfo> materialInfo);

    const std::shared_ptr<MaterialInfo> materialInfo() const;

    bool setAttributes(const std::unordered_map<std::string, std::shared_ptr<iDynTree::XMLAttribute>>& attributes) override;
    std::shared_ptr<XMLElement> childElementForName(const std::string& name) override;
};

#endif /* end of include guard: IDYNTREE_MODELIO_URDF_MATERIALELEMENT_H */

