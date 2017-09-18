#include <iostream>
#include "FBXImporter.h"

int main(int argc, char const *argv[]) {
  FBXImporter* fbxImporter = new FBXImporter();
  fbxImporter->importFromBynary("test.fbx");
  return 0;
}
