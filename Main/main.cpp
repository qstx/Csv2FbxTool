#include "pch.h"
#include <iostream>

#include "Mesh.h"
#include "RDCsvReader.h"

#include <fbxsdk.h>
#include <fbxsdk/fileio/fbxiosettings.h>

int main(int argc,char* argv[]) {
    csv::RDCsvReader csv_reader("Assets/Nemo.csv");
    FbxManager* lSdkManager = FbxManager::Create();

    // Create an IOSettings object.
    FbxIOSettings* ios = FbxIOSettings::Create(lSdkManager, IOSROOT);
    lSdkManager->SetIOSettings(ios);

    // ... Configure the FbxIOSettings object here ...

    // Create an exporter.
    FbxExporter* lExporter = FbxExporter::Create(lSdkManager, "FbxExporter");

    // Declare the path and filename of the file to which the scene will be exported.
    // In this case, the file will be in the same directory as the executable.
    const char* lFilename = "Assets/Nemo.fbx";
    // Set the export format to ASCII
    int lFormat = lSdkManager->GetIOPluginRegistry()->FindWriterIDByDescription("FBX ascii (*.fbx)");
    // Initialize the exporter.
    bool lExportStatus = lExporter->Initialize(lFilename, lFormat, lSdkManager->GetIOSettings());

    if (!lExportStatus) {
        printf("Call to FbxExporter::Initialize() failed.\n");
        printf("Error returned: %s\n\n", lExporter->GetStatus().GetErrorString());
        return false;
    }

    // Create a new scene so it can be populated by the imported file.
    FbxScene* lScene = FbxScene::Create(lSdkManager, "FbxScene");
    // 创建FBX节点和网格
    FbxNode* lMeshNode = FbxNode::Create(lScene, "FbxMeshNode");
    FbxMesh* lMesh = FbxMesh::Create(lScene, "FbxMesh");

    lMeshNode->SetNodeAttribute(lMesh);
    lScene->GetRootNode()->AddChild(lMeshNode);

    std::shared_ptr<mesh::Mesh> tmp_mesh = csv_reader.GetMesh();
    // 设置顶点数量
    lMesh->InitControlPoints(tmp_mesh->Size());
    FbxVector4* lControlPoints = lMesh->GetControlPoints();

    FbxGeometryElementNormal* lElementNormal= lMesh->CreateElementNormal();
    lElementNormal->SetMappingMode(FbxGeometryElement::eByControlPoint);
    lElementNormal->SetReferenceMode(FbxGeometryElement::eDirect);
    FbxGeometryElementTangent* lElementTangent = lMesh->CreateElementTangent();
    lElementTangent->SetMappingMode(FbxGeometryElement::eByControlPoint);
    lElementTangent->SetReferenceMode(FbxGeometryElement::eDirect);
    FbxGeometryElementVertexColor* lElementVertexColor = lMesh->CreateElementVertexColor();
    lElementVertexColor->SetMappingMode(FbxGeometryElement::eByControlPoint);
    lElementVertexColor->SetReferenceMode(FbxGeometryElement::eDirect);
    FbxGeometryElementUV* lElementUV = lMesh->CreateElementUV("UV0");
    lElementUV->SetMappingMode(FbxGeometryElement::eByControlPoint);
    lElementUV->SetReferenceMode(FbxGeometryElement::eDirect);

    for (int i = 0; i < tmp_mesh->Size(); ++i) {
        auto position = tmp_mesh->Get_Position(i);
        lControlPoints[i] = FbxVector4(position[0],position[1],position[2]);
        auto normal = tmp_mesh->Get_Normal(i);
        lElementNormal->GetDirectArray().Add(FbxVector4(normal[0], normal[1], normal[2]));
        auto tangent = tmp_mesh->Get_Tangent(i);
        lElementTangent->GetDirectArray().Add(FbxVector4(tangent[0], tangent[1], tangent[2], tangent[3]));
        auto color = tmp_mesh->Get_Color(i);
        lElementVertexColor->GetDirectArray().Add(FbxColor(color[0], color[1], color[2], color[3]));
        auto uv0 = tmp_mesh->Get_Texcoord0(i);
        lElementUV->GetDirectArray().Add(FbxVector2(uv0[0], uv0[1]));
    }
    // 创建面
    for (const auto& face : tmp_mesh->faces) {
        lMesh->BeginPolygon();
        lMesh->AddPolygon(face[0]);
        lMesh->AddPolygon(face[1]);
        lMesh->AddPolygon(face[2]);
        lMesh->EndPolygon();
    }

    // Export the scene to the file.
    lExporter->Export(lScene);

    // Destroy the exporter.
    lExporter->Destroy();
}