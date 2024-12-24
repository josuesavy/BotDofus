#ifndef ALLIANCELISTAPPLICATIONANSWERMESSAGE_H
#define ALLIANCELISTAPPLICATIONANSWERMESSAGE_H

#include "src/protocol/network/types/data/game/social/application/SocialApplicationInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/PaginationAnswerAbstractMessage.h"

class AllianceListApplicationAnswerMessage : public PaginationAnswerAbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceListApplicationAnswerMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceListApplicationAnswerMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceListApplicationAnswerMessage(FuncTree tree);
  AllianceListApplicationAnswerMessage();

  QList<QSharedPointer<SocialApplicationInformation>> applies;

private:
  void _appliestreeFunc(Reader *input);
  void _appliesFunc(Reader *input);

  FuncTree _appliestree;
};

#endif // ALLIANCELISTAPPLICATIONANSWERMESSAGE_H