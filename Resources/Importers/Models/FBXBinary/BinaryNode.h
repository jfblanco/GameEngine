#ifndef __ENGINE__IMPORTER_FBXIMPORTER_BYNARY_NODE_
#define __ENGINE__IMPORTER_FBXIMPORTER_BYNARY_NODE_

#include <vector>

	class BinaryProperty;
	class BinaryNode {
	private:
		unsigned long endOffset;
		unsigned long numProperties;
		unsigned long propertyListLen;
		unsigned char nameLen;
		char* nodeName;
		std::vector<BinaryProperty*> properties;
		BinaryNode* nestedList;
		char* nullRecord;//length: 13
	public:
		BinaryNode();
		~BinaryNode();
		int getNameLength();
		void setNodeName(char*);
		void setStaticInfoFromBuffer(char*);
		void printNode();
		void addProperty(BinaryProperty*);
		unsigned long getPropertiesLength();
	};

#endif
