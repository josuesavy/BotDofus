#ifndef GUILDEMBLEM_H
#define GUILDEMBLEM_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class GuildEmblem : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildEmblem(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildEmblem(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildEmblem(FuncTree tree);
  GuildEmblem();
  bool operator==(const GuildEmblem &compared);

  uint symbolShape;
  int symbolColor;
  uint backgroundShape;
  int backgroundColor;

private:
  void _symbolShapeFunc(Reader *input);
  void _symbolColorFunc(Reader *input);
  void _backgroundShapeFunc(Reader *input);
  void _backgroundColorFunc(Reader *input);
};

#endif // GUILDEMBLEM_H