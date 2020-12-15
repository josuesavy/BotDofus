#ifndef ICONNAMEDPRESET_H
#define ICONNAMEDPRESET_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/presets/PresetsContainerPreset.h"
#include "src/engines/io/network/utils/FuncTree.h"

class IconNamedPreset : public PresetsContainerPreset
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_IconNamedPreset(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_IconNamedPreset(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_IconNamedPreset(FuncTree tree);
  IconNamedPreset();
  bool operator==(const IconNamedPreset &compared);

  uint iconId;
  QString name;

private:
  void _iconIdFunc(Reader *input);
  void _nameFunc(Reader *input);
};

#endif // ICONNAMEDPRESET_H