#ifndef ALLIANCEPLAYERAPPLICATIONABSTRACTMESSAGE_H
#define ALLIANCEPLAYERAPPLICATIONABSTRACTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AlliancePlayerApplicationAbstractMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AlliancePlayerApplicationAbstractMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AlliancePlayerApplicationAbstractMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AlliancePlayerApplicationAbstractMessage(FuncTree tree);
  AlliancePlayerApplicationAbstractMessage();
};

#endif // ALLIANCEPLAYERAPPLICATIONABSTRACTMESSAGE_H