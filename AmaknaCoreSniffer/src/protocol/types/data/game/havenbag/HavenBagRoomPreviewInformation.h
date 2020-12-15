#ifndef HAVENBAGROOMPREVIEWINFORMATION_H
#define HAVENBAGROOMPREVIEWINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class HavenBagRoomPreviewInformation : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HavenBagRoomPreviewInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HavenBagRoomPreviewInformation(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HavenBagRoomPreviewInformation(FuncTree tree);
  HavenBagRoomPreviewInformation();
  bool operator==(const HavenBagRoomPreviewInformation &compared);

  uint roomId;
  int themeId;

private:
  void _roomIdFunc(Reader *input);
  void _themeIdFunc(Reader *input);
};

#endif // HAVENBAGROOMPREVIEWINFORMATION_H