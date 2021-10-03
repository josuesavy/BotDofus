#ifndef ALIGNMENTWAREFFORTDONATEPREVIEWMESSAGE_H
#define ALIGNMENTWAREFFORTDONATEPREVIEWMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class AlignmentWarEffortDonatePreviewMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AlignmentWarEffortDonatePreviewMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AlignmentWarEffortDonatePreviewMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AlignmentWarEffortDonatePreviewMessage(FuncTree tree);
  AlignmentWarEffortDonatePreviewMessage();

  double xp;

private:
  void _xpFunc(Reader *input);
};

#endif // ALIGNMENTWAREFFORTDONATEPREVIEWMESSAGE_H