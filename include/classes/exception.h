/*
 * Quantum++
 *
 * Copyright (c) 2013 - 2017 Vlad Gheorghiu (vgheorgh@gmail.com)
 *
 * This file is part of Quantum++.
 *
 * Quantum++ is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Quantum++ is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Quantum++.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
* \file classes/exception.h
* \brief Exceptions
*/

#ifndef CLASSES_EXCEPTION1_H_
#define CLASSES_EXCEPTION1_H_

namespace qpp
{
/**
* \namespace qpp::exception
* \brief Quantum++ exception hierarchy namespace
*/
namespace exception
{
/**
* \class qpp::exception::Exception
* \brief Base class for generating Quantum++ custom exceptions
*
* Derive from this class if more exceptions are needed, making sure to override
* qpp::exception::Exception::type_description() in the derived class and to
* inherit the constructor qpp::exception::Exception::Exception(). Preferably 
* keep your newly defined exception classes in the namespace qpp::exception.
*
* Example:
* \code
* namespace qpp
* {
* namespace exception
* {
*     class ZeroSize : public Exception
*     {
*     public:
*         std::string type_description() const override
*         {
*             return "Object has zero size";
*         }
*
*         // inherit the base class' qpp::exception::Exception constructor
*         using Exception::Exception;
*     };
* } // namespace exception
* } // namespace qpp
* \endcode
*/
class Exception : public std::exception
{
private:
    std::string where_;
public:
    /**
    * \brief Constructs an exception
    *
    * \param where Text representing where the exception occurred
    */
    Exception(const std::string& where) : where_{where}
    {}

    /**
    * \brief Overrides std::exception::what()
    *
    * \return Exception description
    */
    virtual const char* what() const noexcept override
    {
        std::string msg_;
        msg_ += "IN ";
        msg_ += where_;
        msg_ += ": ";
        msg_ += this->type_description();
        msg_ += "!";
        return msg_.c_str();
    }

    /**
    * \brief Exception type description
    *
    * \return Exception type description
    */
    virtual std::string type_description() const = 0;
}; /* class Exception */

inline std::string Exception::type_description() const
{
    return "qpp::exception::Exception";
}

/**
* \class qpp::exception::Unknown
* \brief Unknown exception
*
* Thrown when no other exception is suitable (not recommended, it is better to
* define another suitable exception type)
*/
class Unknown : public Exception
{
public:
    std::string type_description() const override
    {
        return "UNKNOWN EXCEPTION";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::ZeroSize
* \brief Object has zero size exception
*
* Zero sized object, e.g. empty Eigen::Matrix or std::vector with no elements
*/
class ZeroSize : public Exception
{
public:
    std::string type_description() const override
    {
        return "Object has zero size";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::MatrixNotSquare
* \brief Matrix is not square exception
*
* Eigen::Matrix is not a square matrix
*/
class MatrixNotSquare : public Exception
{
public:
    std::string type_description() const override
    {
        return "Matrix is not square";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::MatrixNotCvector
* \brief Matrix is not a column vector exception
*
* Eigen::Matrix is not a column vector
*/
class MatrixNotCvector : public Exception
{
public:
    std::string type_description() const override
    {
        return "Matrix is not a column vector";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::MatrixNotRvector
* \brief Matrix is not a row vector exception
*
* Eigen::Matrix is not a row vector
*/
class MatrixNotRvector : public Exception
{
public:
    std::string type_description() const override
    {
        return "Matrix is not a row vector";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::MatrixNotVector
* \brief Matrix is not a vector exception
*
* Eigen::Matrix is not a row or column vector
*/
class MatrixNotVector : public Exception
{
public:
    std::string type_description() const override
    {
        return "Matrix is not a vector";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::MatrixNotSquareNorCvector
* \brief Matrix is not square nor column vector exception
*
* Eigen::Matrix is not a square matrix nor a column vector
*/
class MatrixNotSquareNorCvector : public Exception
{
public:
    std::string type_description() const override
    {
        return "Matrix is not square nor column vector";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::MatrixNotSquareNorRvector
* \brief Matrix is not square nor row vector exception
*
* Eigen::Matrix is not a square matrix nor a row vector
*/
class MatrixNotSquareNorRvector : public Exception
{
public:
    std::string type_description() const override
    {
        return "Matrix is not square nor row vector";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::MatrixNotSquareNorVector
* \brief Matrix is not square nor vector exception
*
* Eigen::Matrix is not a square matrix nor a row/column vector
*/
class MatrixNotSquareNorVector : public Exception
{
public:
    std::string type_description() const override
    {
        return "Matrix is not square nor vector";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::MatrixMismatchSubsys
* \brief Matrix mismatch subsystems exception
*
* Matrix size mismatch subsystem sizes (e.g. in qpp::apply())
*/
class MatrixMismatchSubsys : public Exception
{
public:
    std::string type_description() const override
    {
        return "Matrix mismatch subsystems";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::DimsInvalid
* \brief Invalid dimension(s) exception
*
* std::vector<idx> of dimensions has zero size or contains zeros
*/
class DimsInvalid : public Exception
{
public:
    std::string type_description() const override
    {
        return "Invalid dimension(s)";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::DimsNotEqual
* \brief Dimensions not equal exception
*
* Local/global dimensions are not equal
*/
class DimsNotEqual : public Exception
{
public:
    std::string type_description() const override
    {
        return "Dimensions not equal";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::DimsMismatchMatrix
* \brief Dimension(s) mismatch matrix size exception
*
* Product of the elements of std::vector<idx> of dimensions is not equal to
* the number of rows of the Eigen::Matrix (assumed to be a square matrix)
*/
class DimsMismatchMatrix : public Exception
{
public:
    std::string type_description() const override
    {
        return "Dimension(s) mismatch matrix size";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::DimsMismatchCvector
* \brief Dimension(s) mismatch column vector size exception
*
* Product of the elements of std::vector<idx> of dimensions is not equal to
* the number of elements of the Eigen::Matrix (assumed to be a column vector)
*/
class DimsMismatchCvector : public Exception
{
public:
    std::string type_description() const override
    {
        return "Dimension(s) mismatch column vector size";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::DimsMismatchRvector
* \brief Dimension(s) mismatch row vector size exception
*
* Product of the elements of std::vector<idx> of dimensions is not equal to
* the number of elements of the Eigen::Matrix (assumed to be a row vector)
*/
class DimsMismatchRvector : public Exception
{
public:
    std::string type_description() const override
    {
        return "Dimension(s) mismatch row vector size";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::DimsMismatchVector
* \brief Dimension(s) mismatch vector size exception
*
* Product of the elements of std::vector<idx> of dimensions is not equal to
* the number of elements of the Eigen::Matrix (assumed to be a row/column
* vector)
*/
class DimsMismatchVector : public Exception
{
public:
    std::string type_description() const override
    {
        return "Dimension(s) mismatch vector size";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::SubsysMismatchDims
* \brief Subsystems mismatch dimensions exception
*
* std::vector<idx> of subsystem labels has duplicates, or has entries that are
* larger than the size of the std::vector<idx> of dimensions
*/
class SubsysMismatchDims : public Exception
{
public:
    std::string type_description() const override
    {
        return "Subsystems mismatch dimensions";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::PermInvalid
* \brief Invalid permutation exception
*
* std::vector<idx> does note represent a valid permutation
*/
class PermInvalid : public Exception
{
public:
    std::string type_description() const override
    {
        return "Invalid permutation";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::PermMismatchDims
* \brief Permutation mismatch dimensions exception
*
* Size of the std::vector<idx> representing the permutation is different from
* the size of the std::vector<idx> of dimensions
*/
class PermMismatchDims : public Exception
{
public:
    std::string type_description() const override
    {
        return "Permutation mismatch dimensions";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::NotQubitMatrix
* \brief Matrix is not 2 x 2 exception
*
* Eigen::Matrix is not 2 x 2
*/
class NotQubitMatrix : public Exception
{
public:
    std::string type_description() const override
    {
        return "Matrix is not 2 x 2";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::NotQubitCvector
* \brief Column vector is not 2 x 1 exception
*
* Eigen::Matrix is not 2 x 1
*/
class NotQubitCvector : public Exception
{
public:
    std::string type_description() const override
    {
        return "Column vector is not 2 x 1";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::NotQubitRvector
* \brief Row vector is not 1 x 2 exception
*
* Eigen::Matrix is not 1 x 2
*/
class NotQubitRvector : public Exception
{
public:
    std::string type_description() const override
    {
        return "Row vector is not 1 x 2";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::NotQubitVector
* \brief Vector is not 2 x 1 nor 1 x 2 exception
*
* Eigen::Matrix is not 2 x 1 nor 1 x 2
*/
class NotQubitVector : public Exception
{
public:
    std::string type_description() const override
    {
        return "Vector is not 2 x 1 nor 1 x 2";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::NotQubitSubsys
* \brief Subsystems are not qubits exception
*
* Subsystems are not 2-dimensional (qubits)
*/
class NotQubitSubsys : public Exception
{
public:
    std::string type_description() const override
    {
        return "Subsystems are not qubits";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::NotBipartite
* \brief Not bi-partite exception
*
* std::vector<idx> of dimensions has size different from 2
*/
class NotBipartite : public Exception
{
public:
    std::string type_description() const override
    {
        return "Not bi-partite";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::NoCodeword
* \brief Codeword does not exist exception
*
* Codeword does not exist, thrown when calling qpp::Codes::codeword() with an
* invalid index
*/
class NoCodeword : public Exception
{
public:
    std::string type_description() const override
    {
        return "Codeword does not exist";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::OutOfRange
* \brief Parameter out of range exception
*
* Parameter out of range
*/
class OutOfRange : public Exception
{
public:
    std::string type_description() const override
    {
        return "Parameter out of range";
    }

    using Exception::Exception;
};


/**
* \class qpp::exception::TypeMismatch
* \brief Type mismatch exception
*
* Scalar types do not match
*/
class TypeMismatch : public Exception
{
public:
    std::string type_description() const override
    {
        return "Type mismatch";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::SizeMismatch
* \brief Size mismatch exception
*
* Sizes do not match
*/
class SizeMismatch : public Exception
{
public:
    std::string type_description() const override
    {
        return "Size mismatch";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::UndefinedType
* \brief Not defined for this type exception
*
* Templated specialization is not defined for this type
*/
class UndefinedType : public Exception
{
public:
    std::string type_description() const override
    {
        return "Not defined for this type";
    }

    using Exception::Exception;
};

/**
* \class qpp::exception::CustomException
* \brief Custom exception
*
* Custom exception, the user must provide a custom message
*/
class CustomException : public Exception
{
    std::string what_{};

    std::string type_description() const override
    {
        return "CUSTOM EXCEPTION " + what_;
    }

public:
    CustomException(const std::string& where, const std::string& what) :
            Exception{where}, what_{what}
    {}
};

} /* namespace exceptions */
} /* namespace qpp */

#endif /* CLASSES_EXCEPTION1_H_ */
