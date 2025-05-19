#pragma once
#include <string>
#include <RectI.h>
#include <RectF.h>
#include <Color.h>
#include <Flip.h>
#include <Vertex.h>

namespace buki {
    struct Camera;
    struct IGraphics
    {
        virtual bool Initialize(const std::string& title, int w, int h) = 0; // Initialise le système graphique avec un titre de fenêtre et des dimensions spécifiées.

        virtual void Shutdown() = 0; // Ferme et nettoie le système graphique.

        virtual void SetColor(const Color& color) = 0; // Définit la couleur actuelle pour les opérations de dessin.

        virtual void Clear() = 0; // Efface le buffer d'affichage actuel.

        virtual void Present() = 0; // Présente le buffer actuel à l'écran.

        virtual void DrawRect(float x, float y, float w, float h, const Color& color) = 0; // Dessine un rectangle avec des dimensions et une couleur spécifiées.

        virtual void DrawRect(float x, float y, float w, float h, float angle, const Color& color) = 0; // Dessine un rectangle avec des dimensions et une couleur spécifiées avec angle.

        virtual void DrawRect(const RectF& rect, const Color& color) = 0; // Dessine un rectangle en utilisant un objet RectF et une couleur spécifiée.

        virtual void FillRect(float x, float y, float w, float h, const Color& color) = 0; // Remplit un rectangle avec une couleur.

        virtual void FillRect(float x, float y, float w, float h, float angle, const Color& color) = 0; // Remplit un rectangle avec une couleur et un angle.

        virtual void FillRect(const RectF& rect, const Color& color) = 0; // Remplit un rectangle défini par un RectF avec une couleur spécifiée.

        virtual void DrawLine(float x1, float y1, float x2, float y2, const Color& color) = 0; // Dessine une ligne entre deux points avec une couleur spécifiée.

        virtual size_t LoadTexture(const std::string& filename) = 0; // Charge une texture à partir d'un fichier et retourne son identifiant.

        virtual void DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color) = 0; // Dessine une texture avec des options de transformation.

        virtual void DrawTexture(size_t id, const RectI& src, const RectF& dst, const Color& color) = 0;

        virtual void DrawTexture(size_t id, const RectF& dst, const Color& color) = 0; // Dessine une texture dans un rectangle de destination spécifié.

        virtual void DrawTexture(size_t id, const Color& color) = 0; // Dessine une texture avec une couleur spécifiée.

        virtual void GetTextureSize(size_t id, int* w, int* h) = 0; // Récupère les dimensions d'une texture.

        virtual size_t LoadFont(const std::string& filename, int fontSize) = 0; // Charge une police à partir d'un fichier et retourne son identifiant.

        virtual void DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color) = 0; // Dessine une chaîne de caractères avec une police et une couleur spécifiées.

        virtual void GetTextSize(const std::string& text, size_t fontId, float* w, float* h) = 0; // Calcule les dimensions d'une chaîne de texte rendue.

        virtual void DrawTriangle(Vertex vertex1, Vertex vertex2, Vertex vertex3) = 0; // Dessine un triangle avec 3 points et une couleur spécifiés.
        
        virtual void FillTriangle(Vertex vertex1, Vertex vertex2, Vertex vertex3) = 0; // Dessine un triangle avec 3 points et une couleur spécifiés.

        virtual void DrawCircle(float x, float y, float r, float angle, const Color& color) = 0; // Dessine un cercle avec un rayon et une couleur spécifiés.
        
        virtual void FillCircle(float x, float y, float r, float angle, const Color& color) = 0; // Remplit un cercle avec un rayon et une couleur spécifiés.

        virtual void DrawPolygon(float x, float y, float r, int sides, const Color& color) = 0; // Dessine un polygon avec un rayon, une couleur et un nb de cotés spécifiés.

        virtual void FillPolygon(float x, float y, float r, float angle, int sides, const Color& color) = 0; // Remplit un polygon avec un rayon, une couleur et un nb de cotés spécifiés.

        virtual void DrawPoint(float x, float y, const Color& color) = 0; // Dessine un point à une position spécifiée.

        virtual void GetWindowSize(float* w, float* h) = 0; // Récupère les dimensions de la fenêtre de rendu.

        virtual void GetWindowSizeScreen(int* w, int* h) = 0; // Récupère les dimensions de la fenêtre de rendu au monde.

        virtual uint32_t GetWindowID() = 0; // returns the id of the window

        virtual void SetCameraPosition(const Vector2 _pos) = 0;
        virtual Camera* GetCamera() = 0;
    };
}
