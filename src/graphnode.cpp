#include "graphnode.h"
#include <iostream>
#include "graphedge.h"

GraphNode::GraphNode(int id) { _id = id; }

GraphNode::~GraphNode() {
  // delete _chatBot;
  // No need to delete _chatBot because it an unique pointer
}

void GraphNode::AddToken(std::string token) { _answers.push_back(token); }

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge) {
  _childEdges.push_back(std::move(edge));
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge) {
  _parentEdges.push_back(edge);
}
void GraphNode::MoveChatbotHere(ChatBot &&chatbot) {
  _chatBot = std::move(chatbot);  // Call the move assignment operator
  _chatBot.SetCurrentNode(this);  // Set the current node
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode) {
  ChatBot chatbot = std::move(_chatBot);
  newNode->MoveChatbotHere(std::move(chatbot));  // Call the move constructor
}
GraphEdge *GraphNode::GetChildEdgeAtIndex(int index) {
  return _childEdges[index].get();
}
