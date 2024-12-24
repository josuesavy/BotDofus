#ifndef HAVENBAGFURNITURESREQUESTMESSAGE_H
#define HAVENBAGFURNITURESREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class HavenBagFurnituresRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HavenBagFurnituresRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HavenBagFurnituresRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HavenBagFurnituresRequestMessage(FuncTree tree);
  HavenBagFurnituresRequestMessage();

  QList<uint> cellIds;
  QList<int> funitureIds;
  QList<uint> orientations;

private:
  void _cellIdstreeFunc(Reader *input);
  void _cellIdsFunc(Reader *input);
  void _funitureIdstreeFunc(Reader *input);
  void _funitureIdsFunc(Reader *input);
  void _orientationstreeFunc(Reader *input);
  void _orientationsFunc(Reader *input);

  FuncTree _cellIdstree;
  FuncTree _funitureIdstree;
  FuncTree _orientationstree;
};

#endif // HAVENBAGFURNITURESREQUESTMESSAGE_H