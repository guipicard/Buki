#pragma once
#include <string>
#include <RectI.h>
#include <RectF.h>
#include <Color.h>
#include <Flip.h>

namespace buki {
    class IGraphics
    {
    public:
        virtual bool Initialize(const std::string& title, int w, int h) = 0; // Initialise le syst�me graphique avec un titre de fen�tre et des dimensions sp�cifi�es.

        virtual void Shutdown() = 0; // Ferme et nettoie le syst�me graphique.

        virtual void SetColor(const Color& color) = 0; // D�finit la couleur actuelle pour les op�rations de dessin.

        virtual void Clear() = 0; // Efface le buffer d'affichage actuel.

        virtual void Present() = 0; // Pr�sente le buffer actuel � l'�cran.

        virtual void DrawRect(float x, float y, float w, float h, const Color& color) = 0; // Dessine un rectangle avec des dimensions et une couleur sp�cifi�es.

        virtual void DrawRect(const RectF& rect, const Color& color) = 0; // Dessine un rectangle en utilisant un objet RectF et une couleur sp�cifi�e.

        virtual void FillRect(float x, float y, float w, float h, const Color& color) = 0; // Remplit un rectangle avec une couleur.

        virtual void FillRect(const RectF& rect, const Color& color) = 0; // Remplit un rectangle d�fini par un RectF avec une couleur sp�cifi�e.

        virtual void DrawLine(float x1, float y1, float x2, float y2, const Color& color) = 0; // Dessine une ligne entre deux points avec une couleur sp�cifi�e.

        virtual size_t LoadTexture(const std::string& filename) = 0; // Charge une texture � partir d'un fichier et retourne son identifiant.

        virtual void DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color) = 0; // Dessine une texture avec des options de transformation.

        virtual void DrawTexture(size_t id, const RectF& dst, const Color& color) = 0; // Dessine une texture dans un rectangle de destination sp�cifi�.

        virtual void DrawTexture(size_t id, const Color& color) = 0; // Dessine une texture avec une couleur sp�cifi�e.

        virtual void GetTextureSize(size_t id, int* w, int* h) = 0; // R�cup�re les dimensions d'une texture.

        virtual size_t LoadFont(const std::string& filename, int fontSize) = 0; // Charge une police � partir d'un fichier et retourne son identifiant.

        virtual void DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color) = 0; // Dessine une cha�ne de caract�res avec une police et une couleur sp�cifi�es.

        virtual void GetTextSize(const std::string& text, size_t fontId, int* w, int* h) = 0; // Calcule les dimensions d'une cha�ne de texte rendue.

        virtual void DrawCircle(float x, float y, float r, const Color& color) = 0; // Dessine un cercle avec un rayon et une couleur sp�cifi�s.

        virtual void DrawPoint(float x, float y, const Color& color) = 0; // Dessine un point � une position sp�cifi�e.

        virtual void GetWindowSize(int* w, int* h) = 0; // R�cup�re les dimensions de la fen�tre de rendu.
    };
}
