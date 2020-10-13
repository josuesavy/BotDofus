#ifndef HAVENBAGPACKLISTMESSAGE_H
#define HAVENBAGPACKLISTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class HavenBagPackListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HavenBagPackListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HavenBagPackListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HavenBagPackListMessage(FuncTree tree);
  HavenBagPackListMessage();

  QList<int> packIds;

private:
  void _packIdstreeFunc(Reader *input);
  void _packIdsFunc(Reader *input);

  FuncTree _packIdstree;
};

#endif // HAVENBAGPACKLISTMESSAGE_H