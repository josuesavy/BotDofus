#ifndef ACTORALIGNMENTINFORMATIONS_H
#define ACTORALIGNMENTINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class ActorAlignmentInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ActorAlignmentInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ActorAlignmentInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ActorAlignmentInformations(FuncTree tree);
  ActorAlignmentInformations();
  bool operator==(const ActorAlignmentInformations &compared);

  int alignmentSide;
  uint alignmentValue;
  uint alignmentGrade;
  double characterPower;

private:
  void _alignmentSideFunc(Reader *input);
  void _alignmentValueFunc(Reader *input);
  void _alignmentGradeFunc(Reader *input);
  void _characterPowerFunc(Reader *input);
};

#endif // ACTORALIGNMENTINFORMATIONS_H