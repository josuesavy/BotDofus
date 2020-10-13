#ifndef INTERACTIVEELEMENT_H
#define INTERACTIVEELEMENT_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/interactive/InteractiveElementSkill.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class InteractiveElement : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_InteractiveElement(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_InteractiveElement(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_InteractiveElement(FuncTree tree);
  InteractiveElement();
  bool operator==(const InteractiveElement &compared);

  uint elementId;
  int elementTypeId;
  QList<QSharedPointer<InteractiveElementSkill>> enabledSkills;
  QList<QSharedPointer<InteractiveElementSkill>> disabledSkills;
  bool onCurrentMap;

private:
  void _elementIdFunc(Reader *input);
  void _elementTypeIdFunc(Reader *input);
  void _enabledSkillstreeFunc(Reader *input);
  void _enabledSkillsFunc(Reader *input);
  void _disabledSkillstreeFunc(Reader *input);
  void _disabledSkillsFunc(Reader *input);
  void _onCurrentMapFunc(Reader *input);

  FuncTree _enabledSkillstree;
  FuncTree _disabledSkillstree;
};

#endif // INTERACTIVEELEMENT_H