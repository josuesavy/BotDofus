#ifndef STATEDELEMENT_H
#define STATEDELEMENT_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class StatedElement : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_StatedElement(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_StatedElement(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_StatedElement(FuncTree tree);
  StatedElement();
  bool operator==(const StatedElement &compared);

  uint elementId;
  uint elementCellId;
  uint elementState;
  bool onCurrentMap;

private:
  void _elementIdFunc(Reader *input);
  void _elementCellIdFunc(Reader *input);
  void _elementStateFunc(Reader *input);
  void _onCurrentMapFunc(Reader *input);
};

#endif // STATEDELEMENT_H