#ifndef ALIGNMENTWAREFFORTPROGRESSIONMESSAGE_H
#define ALIGNMENTWAREFFORTPROGRESSIONMESSAGE_H

#include "src/Protocol/Types/Data/game/context/roleplay/alignment/war/effort/AlignmentWarEffortInformation.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class AlignmentWarEffortProgressionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AlignmentWarEffortProgressionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AlignmentWarEffortProgressionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AlignmentWarEffortProgressionMessage(FuncTree tree);
  AlignmentWarEffortProgressionMessage();

  QList<AlignmentWarEffortInformation> effortProgressions;

private:
  void _effortProgressionstreeFunc(Reader *input);
  void _effortProgressionsFunc(Reader *input);

  FuncTree _effortProgressionstree;
};

#endif // ALIGNMENTWAREFFORTPROGRESSIONMESSAGE_H