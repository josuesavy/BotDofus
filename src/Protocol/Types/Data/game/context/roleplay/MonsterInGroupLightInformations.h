#ifndef MONSTERINGROUPLIGHTINFORMATIONS_H
#define MONSTERINGROUPLIGHTINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class MonsterInGroupLightInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_MonsterInGroupLightInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_MonsterInGroupLightInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_MonsterInGroupLightInformations(FuncTree tree);
  MonsterInGroupLightInformations();
  bool operator==(const MonsterInGroupLightInformations &compared);

  int genericId;
  uint grade;
  uint level;

private:
  void _genericIdFunc(Reader *input);
  void _gradeFunc(Reader *input);
  void _levelFunc(Reader *input);
};

#endif // MONSTERINGROUPLIGHTINFORMATIONS_H