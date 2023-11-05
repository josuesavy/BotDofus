#ifndef SOCIALEMBLEM_H
#define SOCIALEMBLEM_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class SocialEmblem : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SocialEmblem(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SocialEmblem(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SocialEmblem(FuncTree tree);
  SocialEmblem();
  bool operator==(const SocialEmblem &compared);

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

#endif // SOCIALEMBLEM_H