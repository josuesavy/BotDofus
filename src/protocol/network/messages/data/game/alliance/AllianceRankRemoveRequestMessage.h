#ifndef ALLIANCERANKREMOVEREQUESTMESSAGE_H
#define ALLIANCERANKREMOVEREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AllianceRankRemoveRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceRankRemoveRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceRankRemoveRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceRankRemoveRequestMessage(FuncTree tree);
  AllianceRankRemoveRequestMessage();

  uint rankId;
  uint newRankId;

private:
  void _rankIdFunc(Reader *input);
  void _newRankIdFunc(Reader *input);
};

#endif // ALLIANCERANKREMOVEREQUESTMESSAGE_H