#ifndef __ENGINE__IMPORTER_FBXIMPORTER_
#define __ENGINE__IMPORTER_FBXIMPORTER_

#include <fstream>
  class BinaryNode;
  class BinaryProperty;
  class FBXImporter{
    private:
      char* fileBuffer;
      unsigned int version;
      std::ifstream file;

    public:
      FBXImporter();
      ~FBXImporter();

      void importFromBynary(const char*);
      void loadNode(BinaryNode*);
      void loadProperties(BinaryNode*);
      BinaryProperty* loadProperty();
      char* readFromFile(long);
  };

#endif
