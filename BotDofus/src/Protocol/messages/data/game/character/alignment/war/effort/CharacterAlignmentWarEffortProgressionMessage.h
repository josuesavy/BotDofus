#ifndef CHARACTERALIGNMENTWAREFFORTPROGRESSIONMESSAGE_H
#define CHARACTERALIGNMENTWAREFFORTPROGRESSIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class CharacterAlignmentWarEffortProgressionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharacterAlignmentWarEffortProgressionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharacterAlignmentWarEffortProgressionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharacterAlignmentWarEffortProgressionMessage(FuncTree tree);
  CharacterAlignmentWarEffortProgressionMessage();

  double alignmentWarEffortDailyLimit;
  double alignmentWarEffortDailyDonation;
  double alignmentWarEffortPersonalDonation;

private:
  void _alignmentWarEffortDailyLimitFunc(Reader *input);
  void _alignmentWarEffortDailyDonationFunc(Reader *input);
  void _alignmentWarEffortPersonalDonationFunc(Reader *input);
};

#endif // CHARACTERALIGNMENTWAREFFORTPROGRESSIONMESSAGE_H