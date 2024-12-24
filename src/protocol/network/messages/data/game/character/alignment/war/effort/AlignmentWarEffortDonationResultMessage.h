#ifndef ALIGNMENTWAREFFORTDONATIONRESULTMESSAGE_H
#define ALIGNMENTWAREFFORTDONATIONRESULTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class AlignmentWarEffortDonationResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AlignmentWarEffortDonationResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AlignmentWarEffortDonationResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AlignmentWarEffortDonationResultMessage(FuncTree tree);
  AlignmentWarEffortDonationResultMessage();

  int result;

private:
  void _resultFunc(Reader *input);
};

#endif // ALIGNMENTWAREFFORTDONATIONRESULTMESSAGE_H