#include <iostream>

#include "RDCsvReader.h"

//#include <fbxsdk.h>
//#include <fbxsdk/fileio/fbxiosettings.h>

int main() {
    csv::RDCsvReader("Assets/Nemo.csv");
    //while (in.read_row()) {
	//	// do stuff with the data
	//}
    //FbxManager* lSdkManager = FbxManager::Create();

    //// Create an IOSettings object.
    //FbxIOSettings* ios = FbxIOSettings::Create(lSdkManager, IOSROOT);
    //lSdkManager->SetIOSettings(ios);

    //// ... Configure the FbxIOSettings object here ...

    //// Create an exporter.
    //FbxExporter* lExporter = FbxExporter::Create(lSdkManager, "");

    //// Declare the path and filename of the file to which the scene will be exported.
    //// In this case, the file will be in the same directory as the executable.
    //const char* lFilename = "file.fbx";

    //// Initialize the exporter.
    //bool lExportStatus = lExporter->Initialize(lFilename, -1, lSdkManager->GetIOSettings());

    //if (!lExportStatus) {
    //    printf("Call to FbxExporter::Initialize() failed.\n");
    //    printf("Error returned: %s\n\n", lExporter->GetStatus().GetErrorString());
    //    return false;
    //}

    //// Create a new scene so it can be populated by the imported file.
    //FbxScene* lScene = FbxScene::Create(lSdkManager, "myScene");

    //// Export the scene to the file.
    //lExporter->Export(lScene);

    //// Destroy the exporter.
    //lExporter->Destroy();
}