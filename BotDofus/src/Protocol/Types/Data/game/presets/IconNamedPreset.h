#ifndef ICONNAMEDPRESET_H
#define ICONNAMEDPRESET_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/presets/PresetsContainerPreset.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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