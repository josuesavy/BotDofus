#ifndef SURRENDERVOTESTARTMESSAGE_H
#define SURRENDERVOTESTARTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class SurrenderVoteStartMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SurrenderVoteStartMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SurrenderVoteStartMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SurrenderVoteStartMessage(FuncTree tree);
  SurrenderVoteStartMessage();

  bool alreadyCastedVote;
  int numberOfParticipants;
  int castedVoteNumber;
  int voteDuration;

private:
  void _alreadyCastedVoteFunc(Reader *input);
  void _numberOfParticipantsFunc(Reader *input);
  void _castedVoteNumberFunc(Reader *input);
  void _voteDurationFunc(Reader *input);
};

#endif // SURRENDERVOTESTARTMESSAGE_H