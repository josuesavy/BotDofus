#ifndef ALLIANCERIGHTSUPDATEMESSAGE_H
#define ALLIANCERIGHTSUPDATEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AllianceRightsUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceRightsUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceRightsUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceRightsUpdateMessage(FuncTree tree);
  AllianceRightsUpdateMessage();

  uint rankId;
  QList<uint> rights;

private:
  void _rankIdFunc(Reader *input);
  void _rightstreeFunc(Reader *input);
  void _rightsFunc(Reader *input);

  FuncTree _rightstree;
};

#endif // ALLIANCERIGHTSUPDATEMESSAGE_H