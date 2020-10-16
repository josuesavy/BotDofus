#ifndef ALIGNMENTWAREFFORTINFORMATION_H
#define ALIGNMENTWAREFFORTINFORMATION_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class AlignmentWarEffortInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_AlignmentWarEffortInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_AlignmentWarEffortInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_AlignmentWarEffortInformation(FuncTree tree);
  AlignmentWarEffortInformation();
  bool operator==(const AlignmentWarEffortInformation &compared);

  int alignmentSide;
  double alignmentWarEffort;

private:
  void _alignmentSideFunc(Reader *input);
  void _alignmentWarEffortFunc(Reader *input);
};

#endif // ALIGNMENTWAREFFORTINFORMATION_H