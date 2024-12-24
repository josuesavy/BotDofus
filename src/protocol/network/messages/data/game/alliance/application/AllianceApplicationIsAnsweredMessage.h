#ifndef ALLIANCEAPPLICATIONISANSWEREDMESSAGE_H
#define ALLIANCEAPPLICATIONISANSWEREDMESSAGE_H

#include "src/protocol/network/types/data/game/context/roleplay/AllianceInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AllianceApplicationIsAnsweredMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AllianceApplicationIsAnsweredMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AllianceApplicationIsAnsweredMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AllianceApplicationIsAnsweredMessage(FuncTree tree);
  AllianceApplicationIsAnsweredMessage();

  bool accepted;
  QSharedPointer<AllianceInformation> allianceInformation;

private:
  void _acceptedFunc(Reader *input);
  void _allianceInformationtreeFunc(Reader *input);

  FuncTree _allianceInformationtree;
};

#endif // ALLIANCEAPPLICATIONISANSWEREDMESSAGE_H