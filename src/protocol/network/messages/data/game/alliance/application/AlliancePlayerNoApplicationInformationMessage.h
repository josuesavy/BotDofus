#ifndef ALLIANCEPLAYERNOAPPLICATIONINFORMATIONMESSAGE_H
#define ALLIANCEPLAYERNOAPPLICATIONINFORMATIONMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/alliance/application/AlliancePlayerApplicationAbstractMessage.h"

class AlliancePlayerNoApplicationInformationMessage : public AlliancePlayerApplicationAbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AlliancePlayerNoApplicationInformationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AlliancePlayerNoApplicationInformationMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AlliancePlayerNoApplicationInformationMessage(FuncTree tree);
  AlliancePlayerNoApplicationInformationMessage();
};

#endif // ALLIANCEPLAYERNOAPPLICATIONINFORMATIONMESSAGE_H