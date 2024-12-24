#ifndef ALLIANCERANKCREATEREQUESTMESSAGE_H
#define ALLIANCERANKCREATEREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AllianceRankCreateRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceRankCreateRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceRankCreateRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceRankCreateRequestMessage(FuncTree tree);
  AllianceRankCreateRequestMessage();

  uint parentRankId;
  uint gfxId;
  QString name;

private:
  void _parentRankIdFunc(Reader *input);
  void _gfxIdFunc(Reader *input);
  void _nameFunc(Reader *input);
};

#endif // ALLIANCERANKCREATEREQUESTMESSAGE_H