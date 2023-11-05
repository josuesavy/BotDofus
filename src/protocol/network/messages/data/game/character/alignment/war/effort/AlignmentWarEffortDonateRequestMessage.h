#ifndef ALIGNMENTWAREFFORTDONATEREQUESTMESSAGE_H
#define ALIGNMENTWAREFFORTDONATEREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AlignmentWarEffortDonateRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AlignmentWarEffortDonateRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AlignmentWarEffortDonateRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AlignmentWarEffortDonateRequestMessage(FuncTree tree);
  AlignmentWarEffortDonateRequestMessage();

  double donation;

private:
  void _donationFunc(Reader *input);
};

#endif // ALIGNMENTWAREFFORTDONATEREQUESTMESSAGE_H